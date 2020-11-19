# $NetBSD: Makefile,v 1.20 2020/11/19 10:36:57 adam Exp $

DISTNAME=	lz4-1.9.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=lz4/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lz4.github.io/lz4/
COMMENT=	Extremely Fast Compression algorithm
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	lib/liblz4.pc.in
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
