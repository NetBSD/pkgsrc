# $NetBSD: Makefile,v 1.10 2024/02/04 19:12:41 schmonz Exp $

DISTNAME=	libcbor-0.11.0
PKGREVISION=	1
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

PLIST_SUBST+=	PKGVERSION_SANS_TEENY=${PKGVERSION_NOREV:C/\.[0-9]*$//}

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
