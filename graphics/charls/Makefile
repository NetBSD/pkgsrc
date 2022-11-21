# $NetBSD: Makefile,v 1.4 2022/11/21 18:20:42 jperkin Exp $

DISTNAME=	charls-2.3.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=team-charls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/team-charls/charls/
COMMENT=	Jpeg-ls codec library
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/charls.version

PKGCONFIG_OVERRIDE=	src/charls-template.pc

.include "../../mk/bsd.pkg.mk"
