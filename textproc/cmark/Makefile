# $NetBSD: Makefile,v 1.12 2023/01/24 08:27:49 adam Exp $

DISTNAME=	cmark-0.30.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/commonmark/cmark
COMMENT=	CommonMark parsing and rendering library and program in C
LICENSE=	2-clause-bsd

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		${WRKSRC}
PKGCONFIG_OVERRIDE+=	src/libcmark.pc.in

PYTHON_FOR_BUILD_ONLY=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/build/src
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/build/src
TEST_TARGET=	test

post-extract:
	${MKDIR} ${WRKSRC}/build

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
