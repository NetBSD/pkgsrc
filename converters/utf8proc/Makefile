# $NetBSD: Makefile,v 1.6 2019/05/21 17:52:24 wiz Exp $

DISTNAME=	utf8proc-2.4.0
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
