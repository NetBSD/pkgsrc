# $NetBSD: Makefile,v 1.5 2019/04/01 13:19:46 wiz Exp $

DISTNAME=	utf8proc-2.3.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=JuliaLang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://julialang.org/utf8proc/
COMMENT=	Clean C library for processing UTF-8 Unicode data
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c99
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.pkg.mk"
