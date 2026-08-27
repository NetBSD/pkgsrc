# $NetBSD: Makefile,v 1.61 2026/08/27 06:36:13 adam Exp $

DISTNAME=	libebml-1.4.7
CATEGORIES=	devel
MASTER_SITES=	https://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://matroska-org.github.io/libebml/
COMMENT=	Extensible Binary Meta Language support library
LICENSE=	gnu-lgpl-v2.1

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=YES
PKGCONFIG_OVERRIDE=	libebml.pc.in

.include "../../devel/cmake/build.mk"
.include "../../textproc/utf8-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
