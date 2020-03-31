# $NetBSD: Makefile,v 1.7 2020/03/31 17:36:19 wiz Exp $

DISTNAME=	utf8proc-2.5.0
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
