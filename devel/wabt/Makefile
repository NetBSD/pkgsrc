# $NetBSD: Makefile,v 1.22 2023/10/25 09:05:25 adam Exp $

DISTNAME=	wabt-1.0.34
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=WebAssembly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WebAssembly/wabt
COMMENT=	The WebAssembly Binary Toolkit
LICENSE=	apache-2.0

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_LIBWASM=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=OFF

.include "../../devel/cmake/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
