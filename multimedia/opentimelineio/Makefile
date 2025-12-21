# $NetBSD: Makefile,v 1.1 2025/12/21 09:07:20 markd Exp $
#

DISTNAME=	opentimelineio-0.18.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	OpenTimelineIO
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opentimeline.io/
COMMENT=	API and interchange format for editorial timeline information
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DOTIO_FIND_IMATH=ON
CMAKE_CONFIGURE_ARGS+=	-DOTIO_FIND_RAPIDJSON=ON

.include "../../devel/cmake/build.mk"

.include "../../math/imath/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
