# $NetBSD: Makefile,v 1.11 2003/05/08 09:41:29 wiz Exp $
#

VERS=			1.08
DISTNAME=		lzo-${VERS}
PKGNAME=		liblzo-${VERS}
CATEGORIES=		archivers
MASTER_SITES=		http://www.oberhumer.com/opensource/lzo/download/ \
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
