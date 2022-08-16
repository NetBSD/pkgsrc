# $NetBSD: Makefile,v 1.25 2022/08/16 13:02:56 adam Exp $

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
PKGCONFIG_OVERRIDE+=	lib/liblz4.pc.in
TEST_TARGET=		test

# Needed for nanosleep() on Solaris 10, PR pkg/56226
LDFLAGS.SunOS+=		-lrt

.include "../../mk/bsd.pkg.mk"
