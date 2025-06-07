# $NetBSD: Makefile,v 1.3 2025/06/07 15:34:05 vins Exp $

DISTNAME=	yyjson-0.11.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ibireme/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://ibireme.github.io/yyjson/doc/doxygen/html/
COMMENT=	High performance JSON library written in ANSI C
LICENSE=	mit

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	yyjson.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
