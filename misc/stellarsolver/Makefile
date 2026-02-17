# $NetBSD: Makefile,v 1.1 2026/02/17 18:41:01 markd Exp $

DISTNAME=	stellarsolver-2.7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rlancaste/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rlancaste/stellarsolver/
COMMENT=	Astrometric Plate Solver built on Astrometry.net and SEP
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DUSE_QT5=OFF

SUBST_CLASSES+=		bl3
SUBST_SED.bl3+=		-e "s,${BUILDLINK_DIR},${PREFIX},g"
SUBST_FILES.bl3+=	${CMAKE_BUILD_DIR}/CMakeFiles/Export/*/*.cmake
SUBST_STAGE.bl3=	post-build
SUBST_MESSAGE.bl3=	Fix paths to buildlink directories in installed files.

PKGCONFIG_OVERRIDE+=	stellarsolver.pc.cmake

.include "../../devel/cmake/build.mk"

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../graphics/wcslib/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
