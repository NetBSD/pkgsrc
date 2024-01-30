# $NetBSD: Makefile,v 1.14 2024/01/30 20:00:13 adam Exp $

DISTNAME=	cmark-0.31.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/commonmark/cmark
COMMENT=	CommonMark parsing and rendering library and program in C
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	src/libcmark.pc.in
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

PYTHON_FOR_BUILD_ONLY=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/build/src
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/build/src
TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
