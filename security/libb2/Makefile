# $NetBSD: Makefile,v 1.3 2025/07/08 14:09:46 jperkin Exp $

DISTNAME=	libb2-0.98.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=BLAKE2/}
GITHUB_RELEASE=	v0.98.1

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/BLAKE2/libb2/
COMMENT=	C library providing BLAKE2b, BLAKE2s, BLAKE2bp, BLAKE2sp
LICENSE=	cc0-1.0-universal

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CPPFLAGS.SunOS+=	-D__STDC_WANT_LIB_EXT1__=1	# memset_s

PKGCONFIG_OVERRIDE+=	libb2.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
