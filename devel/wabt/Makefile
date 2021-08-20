# $NetBSD: Makefile,v 1.5 2021/08/20 13:52:49 fcambus Exp $

DISTNAME=	wabt-1.0.24
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/WebAssembly/wabt/
COMMENT=	The WebAssembly Binary Toolkit
LICENSE=	apache-2.0

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_TESTS=OFF -DBUILD_LIBWASM=OFF

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"
