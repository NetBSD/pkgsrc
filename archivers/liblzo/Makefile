# $NetBSD: Makefile,v 1.18 2004/12/09 18:56:53 jlam Exp $
#

DISTNAME=	lzo-1.08
PKGNAME=	lib${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/lzo/download/ \
		ftp://ftp.elf.stuba.sk/pub/pc/pack/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzo/
COMMENT=	Portable lossless data compression library written in ANSI C

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

# Don't spuriously detect zlib, as it's not needed for the library.
BUILDLINK_TRANSFORM+=	rm:-lz

.include "../../mk/bsd.pkg.mk"
