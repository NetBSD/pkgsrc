# $NetBSD: Makefile,v 1.5 2001/02/16 13:15:33 wiz Exp $
#

DISTNAME=		lzo-1.06
PKGNAME=		liblzo-1.06
CATEGORIES=		archivers
MASTER_SITES=		http://wildsau.idv.uni-linz.ac.at/mfx/lzo-download/ \
			ftp://wildsau.idv.uni-linz.ac.at/pub/mfx/lzo/ \
			ftp://metalab.unc.edu/pub/Linux/libs/compression/ \
			ftp://ftp.elf.stuba.sk/pub/pc/pack/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://wildsau.idv.uni-linz.ac.at/mfx/lzo.html
COMMENT=		Portable lossless data compression library written in ANSI C

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/acconfig/ltconfig

.include "../../mk/bsd.pkg.mk"
