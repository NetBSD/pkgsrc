# $NetBSD: Makefile,v 1.9 2024/02/04 08:16:38 adam Exp $

DISTNAME=	libcbor-0.11.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=PJK/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PJK/libcbor
COMMENT=	Parsing and generate schema-less binary data format
LICENSE=	mit

USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DWITH_EXAMPLES=OFF

CHECK_PORTABILITY_SKIP+=	misc/hooks/*

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
