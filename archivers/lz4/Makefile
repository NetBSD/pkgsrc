# $NetBSD: Makefile,v 1.17 2019/08/26 07:09:47 adam Exp $

DISTNAME=	lz4-1.9.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=lz4/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	http://lz4.github.io/lz4/
COMMENT=	Extremely Fast Compression algorithm
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	lib/liblz4.pc.in
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
