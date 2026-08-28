# $NetBSD: Makefile,v 1.55 2026/08/28 03:39:46 ryoon Exp $

DISTNAME=	libmatroska-1.7.2
CATEGORIES=	multimedia devel
MASTER_SITES=	https://dl.matroska.org/downloads/libmatroska/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format
LICENSE=	gnu-lgpl-v2.1

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
PKGCONFIG_OVERRIDE=	libmatroska.pc.in

.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.libebml+=	libebml>=1.4.3
.include "../../devel/libebml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
