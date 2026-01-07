# $NetBSD: Makefile,v 1.29 2026/01/07 08:49:04 wiz Exp $

DISTNAME=	libkolabxml-1.1.6
PKGREVISION=	25
CATEGORIES=	textproc
MASTER_SITES=	https://mirror.kolabenterprise.com/pub/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kolab.org/
COMMENT=	Kolab XML Format Schema Definitions Library
LICENSE=	apache-2.0 AND gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

SUBST_CLASSES+=		bl3
SUBST_SED.bl3+=		-e "s,${BUILDLINK_DIR},${PREFIX},g"
SUBST_FILES.bl3+=	${CMAKE_BUILD_DIR}/CMakeFiles/Export/*/*.cmake
SUBST_STAGE.bl3=	post-build
SUBST_MESSAGE.bl3=	Fix paths to buildlink directories in installed files.

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/xsd/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
