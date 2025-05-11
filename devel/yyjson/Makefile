# $NetBSD: Makefile,v 1.2 2025/05/11 07:31:56 vins Exp $

DISTNAME=	yyjson-0.11.0
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
