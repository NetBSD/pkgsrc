# $NetBSD: Makefile,v 1.19 2023/07/09 15:28:30 nia Exp $

DISTNAME=	wabt-1.0.33
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WebAssembly/wabt/
COMMENT=	The WebAssembly Binary Toolkit
LICENSE=	apache-2.0

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

# C++17
GCC_REQD+=	7

CMAKE_ARGS+=	-DBUILD_TESTS=OFF -DBUILD_LIBWASM=OFF

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
