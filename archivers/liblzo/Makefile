# $NetBSD: Makefile,v 1.14 2004/02/09 20:25:09 jlam Exp $
#

DISTNAME=	lzo-1.08
PKGNAME=	lib${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/lzo/download/ \
		ftp://ftp.elf.stuba.sk/pub/pc/pack/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzo/
COMMENT=	Portable lossless data compression library written in ANSI C

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# Don't spuriously detect zlib, as it's not needed for the library.
CONFIGURE_ENV+=	ac_cv_lib_z_gzputs=no

.include "../../mk/bsd.pkg.mk"
