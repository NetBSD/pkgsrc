# $NetBSD: Makefile,v 1.15 2025/08/11 12:21:51 wiz Exp $

DISTNAME=	libcbor-0.12.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=PJK/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PJK/libcbor
COMMENT=	Parsing and generate schema-less binary data format
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_EXAMPLES=OFF

CHECK_PORTABILITY_SKIP+=	misc/hooks/*

PLIST_SUBST+=	PKGVERSION_SANS_TEENY=${PKGVERSION_NOREV:C/\.[0-9]*$//}

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
