# $NetBSD: Makefile,v 1.1 2018/04/30 19:31:47 minskim Exp $

DISTNAME=	utf8proc-2.1.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=JuliaLang/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://julialang.org/utf8proc/
COMMENT=	Clean C library for processing UTF-8 Unicode data
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c99
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/build

CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

INSTALLATION_DIRS+=	include lib

post-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME_NOREV}/utf8proc.h \
		${DESTDIR}${PREFIX}/include/
	${INSTALL_LIB} ${WRKSRC}/libutf8proc.* ${DESTDIR}${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
