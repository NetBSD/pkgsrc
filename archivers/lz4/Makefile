# $NetBSD: Makefile,v 1.29 2024/07/23 06:22:37 adam Exp $

DISTNAME=	lz4-1.10.0
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

# Needed for nanosleep() on Solaris 10, PR pkg/56226
LDFLAGS.SunOS+=		-lrt

.include "../../mk/bsd.pkg.mk"
