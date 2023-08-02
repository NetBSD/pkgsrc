# $NetBSD: Makefile,v 1.3 2023/08/02 19:27:31 nia Exp $

DISTNAME=	ptex-2.1.28
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdas/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ptex.us/
COMMENT=	Per-Face Texture Mapping for Production Rendering
LICENSE=	modified-bsd # with slightly changes spelling

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

TEST_TARGET=	test

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/src/ptex/

# Uses alloca, cannot use standard C++ on NetBSD.
FORCE_CXX_STD=	gnu++03

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
