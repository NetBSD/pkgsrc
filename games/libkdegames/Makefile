# $NetBSD: Makefile,v 1.10 2014/02/01 02:20:47 markd Exp $

DISTNAME=	libkdegames-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	library for the kdegames package

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	KDEGamesConfig.cmake.in
SUBST_SED.path+=	-e 's;KDEGAMES_INCLUDE_DIR .*;KDEGAMES_INCLUDE_DIR "${PREFIX}/include");'

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/openal/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
