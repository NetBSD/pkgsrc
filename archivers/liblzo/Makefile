# $NetBSD: Makefile,v 1.10 2002/08/25 21:49:14 jlam Exp $
#

VERS=			1.08
DISTNAME=		lzo-${VERS}
PKGNAME=		liblzo-${VERS}
CATEGORIES=		archivers
MASTER_SITES=		http://www.oberhumer.com/opensource/lzo/download/ \
			${MASTER_SITE_SUNSITE:=libs/compression/} \
			ftp://ftp.elf.stuba.sk/pub/pc/pack/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.oberhumer.com/opensource/lzo/
COMMENT=		Portable lossless data compression library written in ANSI C

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# Don't spuriously detect zlib, as it's not needed for the library.
CONFIGURE_ENV+=		ac_cv_lib_z_gzputs=no

.include "../../mk/bsd.pkg.mk"
