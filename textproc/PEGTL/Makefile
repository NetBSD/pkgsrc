# $NetBSD: Makefile,v 1.1 2021/05/04 14:19:51 prlw1 Exp $

DISTNAME=	PEGTL-2.8.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=taocpp/}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/taocpp/PEGTL/
COMMENT=	C++ header-only parser combinator library
LICENSE=	mit

# version 3 requires c++17
USE_LANGUAGES=	c++11
USE_CMAKE=	yes

CMAKE_ARGS+=	-DPEGTL_BUILD_EXAMPLES=no
CMAKE_ARGS+=	-DPEGTL_BUILD_TESTS=no
CMAKE_ARGS+=	-DPEGTL_BUILD_TESTS=no

.include "../../mk/bsd.pkg.mk"
