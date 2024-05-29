# $NetBSD: Makefile,v 1.116 2024/05/29 16:32:02 adam Exp $

PKGREVISION= 2
.include "../../devel/git/Makefile.common"

PKGNAME=	git-base-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (base package)

CONFLICTS+=	scmgit-base-[0-9]*
SUPERSEDES+=	scmgit-base-[0-9]*

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_TOOLS+=		sh:run msgfmt bash:test

CFLAGS+=		-DHAVE_DEV_TTY
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-libpcre2=${BUILDLINK_PREFIX.pcre2}
CONFIGURE_ARGS+=	--with-perl=/nonexistent/perl
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--without-python # only needed for git-p4
CONFIGURE_ARGS+=	--without-tcltk

BUILD_TARGET=		all

TEST_TARGET=		test

REPLACE_SH+=		contrib/hooks/post-receive-email
REPLACE_SH+=		contrib/hooks/pre-auto-gc-battery

EGDIR=			${PREFIX}/share/examples/git

GIT_COREDIR=		git-core
GIT_TEMPLATEDIR=	templates

GIT_TEMPLATES=		description info/exclude
GIT_TEMPLATES+=		hooks/applypatch-msg.sample hooks/commit-msg.sample
GIT_TEMPLATES+=		hooks/post-update.sample hooks/pre-applypatch.sample
GIT_TEMPLATES+=		hooks/pre-commit.sample hooks/pre-rebase.sample
GIT_TEMPLATES+=		hooks/prepare-commit-msg.sample hooks/update.sample

GIT_CORE_DATADIR=	share/${GIT_COREDIR}
GIT_CORE_TEMPLATEDIR=	${GIT_CORE_DATADIR}/${GIT_TEMPLATEDIR}

MAKE_DIRS=		${GIT_CORE_TEMPLATEDIR}
MAKE_DIRS+=		${GIT_CORE_TEMPLATEDIR}/hooks
MAKE_DIRS+=		${GIT_CORE_TEMPLATEDIR}/info

REQD_FILES+=		${GIT_TEMPLATES:@.t.@ \
			${EGDIR}/${GIT_TEMPLATEDIR}/${.t.} \
			${PREFIX}/${GIT_CORE_TEMPLATEDIR}/${.t.} \
			@:M*}

CONFIGURE_ENV+=		HOME=${PREFIX}
CONFIGURE_ENV+=		gitexecdir=${GITCOREDIR}

MAKE_FLAGS+=		INSTALL=${INSTALL:Q}
MAKE_FLAGS+=		CC_LD_DYNPATH=${COMPILER_RPATH_FLAG}
MAKE_ENV+=		NO_GITWEB=1
MAKE_ENV+=		NO_PERL=1

GIT_TEMPLATE_INSTDIR=	${EGDIR}/${GIT_TEMPLATEDIR}
MAKE_ENV+=		GIT_TEMPLATE_INSTDIR=${GIT_TEMPLATE_INSTDIR}
MESSAGE_SUBST+=		GIT_TEMPLATE_INSTDIR=${GIT_TEMPLATE_INSTDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	contrib/completion/git-completion.zsh
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	PREFIX

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
CONFIGURE_ENV.NetBSD+=	ac_cv_iconv_omits_bom=no
CONFIGURE_ENV.NetBSD+=	ac_cv_fread_reads_directories=yes
CONFIGURE_ENV.NetBSD+=	ac_cv_snprintf_returns_bogus=no
# Needed to skip calling out to curl-config, which we can't do when
# cross-compiling.  XXX Consider teaching curl's buildlink3.mk to set
# BUILDLINK_LIBS.curl=-lcurl so we can use it here.
MAKE_ENV+=		CURL_LDFLAGS=-lcurl
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1" || ${OPSYS} == "HPUX" || ${OPSYS} == "QNX" || ${OPSYS} == "UnixWare"
SUBST_CLASSES+=		fix-cd-P
SUBST_FILES.fix-cd-P=	t/test-lib.sh
SUBST_MESSAGE.fix-cd-P=	Fixing cd arguments.
SUBST_STAGE.fix-cd-P=	pre-build
SUBST_SED.fix-cd-P=	-e "s/cd -P/cd/g"
.endif

.if ${MACHINE_PLATFORM:MDarwin-*-powerpc*}
.  include "../../devel/macports-legacy-support/buildlink3.mk"
LDFLAGS+=		-lMacportsLegacySupport
MAKE_FLAGS+=		NO_PTHREADS=YesPlease
MAKE_FLAGS+=		NO_UNIX_SOCKETS=YesPlease
CPPFLAGS+=		-DREG_ENHANCED=REG_EXTENDED
CPPFLAGS+=		-DSHA1DC_BIGENDIAN
.endif

SUBST_CLASSES+=			test-shell
SUBST_FILES.test-shell=		t/Makefile
SUBST_MESSAGE.test-shell=	Use bash as TEST_SHELL_PATH
SUBST_STAGE.test-shell=		pre-build
SUBST_SED.test-shell=		-e '/^TEST_SHELL_PATH/ s;$$(SHELL_PATH);${TOOLS_BASH};'

LDFLAGS.SunOS+=		-lnsl

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# configure test gets confused by wrappers dropping -R /
CONFIGURE_ARGS+=	git_cv_ld_dashr=no
.endif

# Prefer to install symlinks.
INSTALL_ENV+=		NO_CROSS_DIRECTORY_HARDLINKS=1
INSTALL_ENV+=		NO_INSTALL_HARDLINKS=1

INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	share/zsh/site-functions
INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/git-completion.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/git
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/git-completion.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_git
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/git-prompt.sh \
		${DESTDIR}${EGDIR}
	# Delete files that are stubs saying git was built without
	# support for perl -- this way you can install git-perlscripts
	# with no conflicts, and git can depend on both git-base and
	# git-perlscripts.
	cd ${DESTDIR}${PREFIX} && \
	rm -f \
		libexec/git-core/git-archimport \
		libexec/git-core/git-cvsexportcommit \
		libexec/git-core/git-cvsimport \
		libexec/git-core/git-cvsserver \
		libexec/git-core/git-instaweb \
		libexec/git-core/git-request-pull \
		libexec/git-core/git-send-email \
		libexec/git-core/git-svn \
		# end of perl list

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.pcre2+=	pcre2>=10.34
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
