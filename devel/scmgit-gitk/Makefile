# $NetBSD: Makefile,v 1.3 2013/01/30 17:39:39 adam Exp $

PKGNAME=	scmgit-gitk-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (gitk)

CONFLICTS+=	scmgit-base<1.7.12nb1
DEPENDS+=	scmgit-base>=1.7.12nb1:../../devel/scmgit-base

USE_LANGUAGES=		c

BUILD_DIRS=		git-gui gitk-git
INSTALL_DIRS=		${BUILD_DIRS}
MAKE_ENV+=		prefix=${PREFIX}

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
