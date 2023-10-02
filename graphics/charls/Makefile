# $NetBSD: Makefile,v 1.5 2023/10/02 20:03:25 nros Exp $

DISTNAME=	charls-2.4.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=team-charls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/team-charls/charls/
COMMENT=	Jpeg-ls codec library
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++14

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/charls.version

PKGCONFIG_OVERRIDE=	src/charls-template.pc

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
