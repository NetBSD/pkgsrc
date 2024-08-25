# $NetBSD: Makefile,v 1.59 2024/08/25 06:18:35 wiz Exp $

DISTNAME=	libebml-1.4.5
CATEGORIES=	devel
MASTER_SITES=	https://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://matroska-org.github.io/libebml/
COMMENT=	Extensible Binary Meta Language support library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++14
CMAKE_CONFIGURE_ARGS+=		-DBUILD_SHARED_LIBS=YES
PKGCONFIG_OVERRIDE=	libebml.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
