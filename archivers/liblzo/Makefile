# $NetBSD: Makefile,v 1.30 2022/10/02 20:59:04 nros Exp $

DISTNAME=	lzo-1.08
PKGNAME=	lib${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/lzo/download/LZO-v1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.oberhumer.com/opensource/lzo/
COMMENT=	Portable lossless data compression library (v1)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

# Don't spuriously detect zlib, as it's not needed for the library.
BUILDLINK_TRANSFORM+=	rm:-lz

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
