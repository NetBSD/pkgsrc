# $NetBSD: Makefile,v 1.26 2025/10/31 21:49:35 adam Exp $

DISTNAME=	wabt-1.0.38
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WebAssembly/wabt
COMMENT=	The WebAssembly Binary Toolkit
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_LIBWASM=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF

.include "../../devel/cmake/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
