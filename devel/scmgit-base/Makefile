# $NetBSD: Makefile,v 1.22 2010/02/03 23:26:17 minskim Exp $
#

.include "../../devel/scmgit/Makefile.common"

PKGNAME=		scmgit-base-${GIT_VERSION}
COMMENT=		GIT Tree History Storage Tool (base package)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		git-[0-9]*		# misc/git

DEPENDS+=		p5-Error>=0.17015:../../devel/p5-Error

USE_LANGUAGES=		c99
USE_TOOLS+=		perl:run sh:run msgfmt

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl:Q}
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat:Q}
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv:Q}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib:Q}

BUILD_TARGET=		all
INSTALL_TARGET=		install

PERL5_CONFIGURE=	no
PERL5_PACKLIST=		auto/Git/.packlist
REPLACE_PERL+=		*.perl */*.perl */*/*.perl
REPLACE_PERL+=		contrib/hooks/update-paranoid

REPLACE_SH+=		contrib/hooks/post-receive-email
REPLACE_SH+=		contrib/hooks/pre-auto-gc-battery

EGDIR=			${PREFIX}/share/examples/scmgit

GIT_COREDIR=		git-core
GIT_TEMPLATEDIR=	templates

GIT_TEMPLATES=		description info/exclude
GIT_TEMPLATES+=		hooks/applypatch-msg.sample hooks/commit-msg.sample 	\
			hooks/post-commit.sample hooks/post-receive.sample	\
			hooks/post-update.sample hooks/pre-applypatch.sample	\
			hooks/pre-commit.sample hooks/pre-rebase.sample		\
			hooks/prepare-commit-msg.sample hooks/update.sample
GIT_TEMPLATES+=

# XXX unused as of now
#GIT_CORE_EXECDIR=	libexec/${GIT_COREDIR}
GIT_CORE_DATADIR=	share/${GIT_COREDIR}
GIT_CORE_TEMPLATEDIR=	${GIT_CORE_DATADIR}/${GIT_TEMPLATEDIR}

MAKE_DIRS=		${GIT_CORE_TEMPLATEDIR}
MAKE_DIRS+=		${GIT_CORE_TEMPLATEDIR}/hooks
MAKE_DIRS+=		${GIT_CORE_TEMPLATEDIR}/info

REQD_FILES+=		${GIT_TEMPLATES:@.t.@\
				${EGDIR}/${GIT_TEMPLATEDIR}/${.t.}\
				${PREFIX}/${GIT_CORE_TEMPLATEDIR}/${.t.}\
			@:M*}


CONFIGURE_ENV+=		HOME=${PREFIX:Q}
CONFIGURE_ENV+=		gitexecdir=${GITCOREDIR:Q}

GIT_TEMPLATE_INSTDIR=	${EGDIR}/${GIT_TEMPLATEDIR}
MAKE_ENV+=		GIT_TEMPLATE_INSTDIR=${GIT_TEMPLATE_INSTDIR:Q}
MESSAGE_SUBST+=		GIT_TEMPLATE_INSTDIR=${GIT_TEMPLATE_INSTDIR}

SUBST_CLASSES+=		fix-paths
SUBST_FILES.fix-paths=	templates/hooks--post-receive.sample
SUBST_MESSAGE.fix-paths=Fixing hard-coded pathnames
SUBST_STAGE.fix-paths=	pre-build
SUBST_VARS.fix-paths=	PREFIX

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1" || ${OPSYS} == "HPUX" || ${OPSYS} == "QNX" || ${OPSYS} == "UnixWare"
SUBST_CLASSES+=		fix-cd-P
SUBST_FILES.fix-cd-P=	git-sh-setup.sh
SUBST_FILES.fix-cd-P+=	t/test-lib.sh
SUBST_MESSAGE.fix-cd-P=	Fixing cd arguments.
SUBST_STAGE.fix-cd-P=	pre-build
SUBST_SED.fix-cd-P=	-e "s/cd -P/cd/g"
.endif

#.include "../../editors/emacs/modules.mk" # XXX TODO (see patch-ad)

.include "options.mk"
.include "../../lang/perl5/module.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
