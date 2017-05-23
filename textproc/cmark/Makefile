# $NetBSD: Makefile,v 1.5 2017/05/23 10:37:20 mef Exp $

DISTNAME=	cmark-0.27.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgm/cmark/
COMMENT=	CommonMark parsing and rendering library and program in C
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PYTHON_FOR_BUILD_ONLY=	yes

PYTHON_VERSIONS_INCOMPATIBLE+=	27

PKGCONFIG_OVERRIDE+=	src/libcmark.pc.in

CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		${WRKSRC}

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/build/src
TEST_TARGET=	test

post-extract:
	${RUN} mkdir -p ${WRKSRC}/build

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
