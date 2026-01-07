# $NetBSD: Makefile,v 1.17 2026/01/07 08:49:05 wiz Exp $

DISTNAME=	nuspell-5.1.6
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=nuspell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://nuspell.github.io/
COMMENT=	Free and Open Source C++ spell checking library
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17 charconv filesystem

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=1 -DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DBUILD_DOCS=OFF

PKGCONFIG_OVERRIDE+=	nuspell.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/catch2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
