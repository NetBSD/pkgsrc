# $NetBSD: Makefile,v 1.7 2022/08/05 20:21:21 adam Exp $

DISTNAME=	libcbor-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=PJK/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PJK/libcbor
COMMENT=	Parsing and generate schema-less binary data format
LICENSE=	mit

USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DWITH_EXAMPLES=OFF

CHECK_PORTABILITY_SKIP+=	misc/hooks/*

.include "../../mk/bsd.pkg.mk"
