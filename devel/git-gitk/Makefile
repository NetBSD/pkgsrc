# $NetBSD: Makefile,v 1.2 2013/09/11 01:26:00 obache Exp $

PKGNAME=	git-gitk-${GIT_VERSION}
COMMENT=	GIT Tree History Storage Tool (gitk)

CONFLICTS+=	git-base<1.7.12nb1
CONFLICTS+=	scmgit-gitk-[0-9]*
SUPERSEDES+=	scmgit-gitk-[0-9]*

DEPENDS+=	git-base>=1.7.12nb1:../../devel/git-base

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

.include "../../devel/git/Makefile.common"

.include "../../mk/bsd.pkg.mk"
