# $NetBSD: Makefile,v 1.53 2023/01/24 18:36:23 wiz Exp $

DISTNAME=	libebml-1.4.4
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://matroska-org.github.io/libebml/
COMMENT=	Extensible Binary Meta Language support library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++14
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=YES
PKGCONFIG_OVERRIDE=	libebml.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
