# $NetBSD: Makefile,v 1.1 2019/06/22 18:54:04 bsiegert Exp $

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
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libb2.pc.in

.include "../../mk/bsd.pkg.mk"
