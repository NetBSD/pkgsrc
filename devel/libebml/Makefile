# $NetBSD: Makefile,v 1.60 2025/08/15 11:04:40 adam Exp $

DISTNAME=	libebml-1.4.5
CATEGORIES=	devel
MASTER_SITES=	https://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://matroska-org.github.io/libebml/
COMMENT=	Extensible Binary Meta Language support library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++14
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=YES
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
PKGCONFIG_OVERRIDE=	libebml.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
