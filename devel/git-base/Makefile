# $NetBSD: Makefile,v 1.95 2022/01/28 09:07:58 adam Exp $

.include "../../devel/git/Makefile.common"

PKGNAME=	git-base-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (base package)

CONFLICTS+=	scmgit-base-[0-9]*
SUPERSEDES+=	scmgit-base-[0-9]*

DEPENDS+=	p5-Error>=0.17015:../../devel/p5-Error
DEPENDS+=	p5-Email-Valid>=0.190:../../mail/p5-Email-Valid
DEPENDS+=	p5-MailTools>=2.11:../../mail/p5-MailTools
DEPENDS+=	p5-Net-SMTP-SSL>=1.01:../../mail/p5-Net-SMTP-SSL
DEPENDS+=	p5-Authen-SASL>=1.0:../../security/p5-Authen-SASL

USE_LANGUAGES=		c99
USE_TOOLS+=		perl:run sh:run msgfmt bash:test

REPLACE_PERL+=		*.perl */*.perl */*/*.perl
REPLACE_PERL+=		contrib/hooks/update-paranoid

CFLAGS+=		-DHAVE_DEV_TTY
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-libpcre2=${BUILDLINK_PREFIX.pcre2}
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
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
MAKE_ENV+=		PERLLIBDIR=${PERL5_INSTALLVENDORLIB}

GIT_TEMPLATE_INSTDIR=	${EGDIR}/${GIT_TEMPLATEDIR}
MAKE_ENV+=		GIT_TEMPLATE_INSTDIR=${GIT_TEMPLATE_INSTDIR}
MESSAGE_SUBST+=		GIT_TEMPLATE_INSTDIR=${GIT_TEMPLATE_INSTDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1" || ${OPSYS} == "HPUX" || ${OPSYS} == "QNX" || ${OPSYS} == "UnixWare"
SUBST_CLASSES+=		fix-cd-P
SUBST_FILES.fix-cd-P=	t/test-lib.sh
SUBST_MESSAGE.fix-cd-P=	Fixing cd arguments.
SUBST_STAGE.fix-cd-P=	pre-build
SUBST_SED.fix-cd-P=	-e "s/cd -P/cd/g"
.endif

SUBST_CLASSES+=			test-shell
SUBST_FILES.test-shell=		t/Makefile
SUBST_MESSAGE.test-shell=	Use bash as TEST_SHELL_PATH
SUBST_STAGE.test-shell=		pre-build
SUBST_SED.test-shell=		-e '/^TEST_SHELL_PATH/ s;$$(SHELL_PATH);${TOOLS_BASH};'

LDFLAGS.SunOS+=		-lintl -lnsl

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
# configure test gets confused by wrappers dropping -R /
CONFIGURE_ARGS+=	git_cv_ld_dashr=no
.endif

# Prefer to install symlinks.
INSTALL_ENV+=		NO_CROSS_DIRECTORY_HARDLINKS=1
INSTALL_ENV+=		NO_INSTALL_HARDLINKS=1

INSTALLATION_DIRS+=	share/bash-completion/completions
INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/git-completion.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/git
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/git-prompt.sh \
		${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.pcre2+=	pcre2>=10.34
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/vars.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
