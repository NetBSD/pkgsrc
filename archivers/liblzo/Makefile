# $NetBSD: Makefile,v 1.8 2001/10/22 01:13:11 mjl Exp $
#

VERS=			1.07
DISTNAME=		lzo-${VERS}
PKGNAME=		liblzo-${VERS}
CATEGORIES=		archivers
MASTER_SITES=		http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/ \
			ftp://wildsau.idv.uni-linz.ac.at/pub/mfx/lzo/ \
			${MASTER_SITE_SUNSITE:=libs/compression/} \
			ftp://ftp.elf.stuba.sk/pub/pc/pack/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://wildsau.idv.uni-linz.ac.at/mfx/lzo.html
COMMENT=		Portable lossless data compression library written in ANSI C

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/acconfig/ltconfig

# Don't spuriously detect zlib, as it's not needed for the library.
CONFIGURE_ENV+=		ac_cv_lib_z_gzputs=no

.include "../../mk/bsd.pkg.mk"
