# $NetBSD: Makefile,v 1.1 2016/10/18 02:47:16 kamil Exp $

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

BUILDLINK_TRANSFORM+=	opt:-std=c++98:-std=gnu++98 # alloca(3)

TEST_TARGET=	test

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/src/ptex/

.include "../../mk/bsd.pkg.mk"
