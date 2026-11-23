# $NetBSD: Makefile,v 1.14 2026/11/23 17:10:04 rhialto Exp $

PKGNAME=	git-gitk-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (gitk)

CONFLICTS+=	git-base<1.7.12nb1
CONFLICTS+=	scmgit-gitk-[0-9]*
SUPERSEDES+=	scmgit-gitk-[0-9]*

DEPENDS+=	git-base>=1.7.12nb1:../../devel/git-base

BUILD_DIRS=	git-gui gitk-git
MAKE_ENV+=	prefix=${PREFIX}
TK90WISH=	${PREFIX}/${TK90_SUBDIR}/bin/wish
MAKE_ENV+=	TCLTK_PATH=${TK90WISH:Q}
MAKE_ENV+=	V=1 # work around bugs in git-gui/Makefile

CONFIGURE_ARGS+=	--with-tcltk=${TK90WISH:Q}

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
ALL_ENV+=		gitexecdir=${PREFIX}/libexec/git-core	# XXX
CONFIGURE_ENV.NetBSD+=	ac_cv_iconv_omits_bom=no
CONFIGURE_ENV.NetBSD+=	ac_cv_fread_reads_directories=yes
CONFIGURE_ENV.NetBSD+=	ac_cv_snprintf_returns_bogus=no
.endif

.include "../../devel/git/Makefile.common"

# does not link against it, but we need TK90_SUBDIR
.include "../../x11/tk90/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
