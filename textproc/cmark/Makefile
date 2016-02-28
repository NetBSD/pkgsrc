# $NetBSD: Makefile,v 1.1 2016/02/28 13:33:58 kamil Exp $

DISTNAME=	cmark-0.24.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=jgm/cmark/}
COMMENT=	CommonMark parsing and rendering library and program in C
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PYTHON_FOR_BUILD_ONLY=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGCONFIG_OVERRIDE+=	src/libcmark.pc.in

CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

TEST_ENV+=	LD_LIBRARY_PATH=${WRKDIR}/build/src
TEST_TARGET=	test

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
