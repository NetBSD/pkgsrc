# $NetBSD: Makefile,v 1.1 2012/09/16 21:50:16 cheusov Exp $

PKGNAME=	scmgit-gitk-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (gitk)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		scmgit-base<1.7.12nb1
DEPENDS+=		scmgit-base>=1.7.12nb1:../../devel/scmgit-base

USE_LANGUAGES=		c

BUILD_DIRS=		git-gui gitk-git
INSTALL_DIRS=		${BUILD_DIRS}
MAKE_ENV+=		prefix=${PREFIX}

PATCHDIR=		${.CURDIR}/../../devel/scmgit-base/patches
DISTINFO_FILE=		${.CURDIR}/../../devel/scmgit-base/distinfo

USE_TOOLS+=		wish:run
CONFIGURE_ARGS+=	--with-tcltk=${WISH:Q}

INSTALLATION_DIRS+=	bin
PLIST_VARS+=		macosx

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && exists(/System/Library/Frameworks/Tk.framework)
.  if exists(/System/Library/Frameworks/Tk.framework/Resources/Wish.app)
WISH_APP=Wish
.  else
WISH_APP=Wish Shell
.  endif
PLIST_SUBST+= WISH_APP=${WISH_APP:Q}
PLIST.macosx=		yes
.endif

.include "../../devel/scmgit/Makefile.common"

.include "../../mk/bsd.pkg.mk"
