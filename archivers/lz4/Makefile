# $NetBSD: Makefile,v 1.28 2024/03/17 12:39:50 nia Exp $

DISTNAME=	lz4-1.9.4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=lz4/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lz4.github.io/lz4/
COMMENT=	Extremely Fast Compression algorithm
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	lib/liblz4.pc.in
BUILD_TARGET=		# empty
TEST_TARGET=		test

MAKE_FLAGS+=		PKGCONFIGDIR=${PREFIX}/lib/pkgconfig

# Needed for nanosleep() on Solaris 10, PR pkg/56226
LDFLAGS.SunOS+=		-lrt

.include "../../mk/bsd.pkg.mk"
