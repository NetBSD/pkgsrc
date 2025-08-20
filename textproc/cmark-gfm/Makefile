# $NetBSD: Makefile,v 1.6 2025/08/20 11:35:12 wiz Exp $

DISTNAME=	0.29.0.gfm.13
PKGREVISION=	1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
GITHUB_PROJECT=	cmark-gfm
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/github/cmark-gfm
COMMENT=	GitHub fork of cmark
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PKGCONFIG_OVERRIDE+=	src/libcmark-gfm.pc.in

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src:${WRKSRC}/${CMAKE_BUILD_DIR}/extensions
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src:${WRKSRC}/${CMAKE_BUILD_DIR}/extensions
TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
