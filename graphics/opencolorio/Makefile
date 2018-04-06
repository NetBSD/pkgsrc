# $NetBSD: Makefile,v 1.1 2018/04/06 03:42:19 maya Exp $

DISTNAME=	v1.0.9
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/^v//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=imageworks/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/imageworks/OpenColorIO/
COMMENT=	Color management solution
LICENSE=	modified-bsd AND mit

GITHUB_PROJECT=	OpenColorIO

WRKSRC=		${WRKDIR}/OpenColorIO-1.0.9
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DUSE_EXTERNAL_TINYXML:BOOL=ON
CMAKE_ARGS+=	-DUSE_EXTERNAL_YAML:BOOL=ON
CMAKE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=OFF
CMAKE_ARGS+=	-DOCIO_BUILD_SHARED:BOOL=ON
CMAKE_ARGS+=	-DOCIO_BUILD_PYGLUE:BOOL=ON

PKGCONFIG_OVERRIDE+=	export/pkgconfig/OpenColorIO.pc.in

BUILDLINK_TRANSFORM+=		rm:-fvisibility=hidden

.include "../../graphics/lcms2/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../textproc/yaml-cpp03/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
