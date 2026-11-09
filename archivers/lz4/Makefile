# $NetBSD: Makefile,v 1.30 2026/11/09 14:20:58 wiz Exp $

DISTNAME=	lz4-1.11.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=lz4/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lz4.github.io/lz4/
COMMENT=	Extremely Fast Compression algorithm
LICENSE=	2-clause-bsd

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	lib/liblz4.pc.in
BUILD_TARGET=		# empty
TEST_TARGET=		test

MAKE_FLAGS+=		PKGCONFIGDIR=${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
