# $NetBSD: Makefile,v 1.53 2025/08/15 11:05:49 adam Exp $

DISTNAME=	libmatroska-1.7.1
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format
LICENSE=	gnu-lgpl-v2.1

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
PKGCONFIG_OVERRIDE=	libmatroska.pc.in

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.libebml+=	libebml>=1.4.3
.include "../../devel/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
