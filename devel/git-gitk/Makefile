# $NetBSD: Makefile,v 1.6 2023/06/14 10:30:11 riastradh Exp $

PKGNAME=	git-gitk-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (gitk)

CONFLICTS+=	git-base<1.7.12nb1
CONFLICTS+=	scmgit-gitk-[0-9]*
SUPERSEDES+=	scmgit-gitk-[0-9]*

DEPENDS+=	git-base>=1.7.12nb1:../../devel/git-base

BUILD_DIRS=		git-gui gitk-git
INSTALL_DIRS=		${BUILD_DIRS}
MAKE_ENV+=		prefix=${PREFIX}

USE_TOOLS+=		wish:run
CONFIGURE_ARGS+=	--with-tcltk=${WISH:Q}

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && exists(/System/Library/Frameworks/Tk.framework)
.  if exists(/System/Library/Frameworks/Tk.framework/Resources/Wish.app)
WISH_APP=	Wish
.  else
WISH_APP=	Wish Shell
.  endif
PLIST_SUBST+=	WISH_APP=${WISH_APP:Q}
.endif

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
ALL_ENV+=		gitexecdir=${PREFIX:Q}/libexec/git-core	# XXX
CONFIGURE_ENV.NetBSD+=	ac_cv_iconv_omits_bom=no
CONFIGURE_ENV.NetBSD+=	ac_cv_fread_reads_directories=yes
CONFIGURE_ENV.NetBSD+=	ac_cv_snprintf_returns_bogus=no
.endif

.include "../../devel/git/Makefile.common"

.include "../../mk/bsd.pkg.mk"
