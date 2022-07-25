# $NetBSD: Makefile,v 1.24 2022/07/25 11:12:18 wiz Exp $

DISTNAME=	lz4-1.9.3
PKGREVISION=	1
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
