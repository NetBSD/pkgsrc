# $NetBSD: Makefile,v 1.4 2000/06/09 06:54:51 jlam Exp $
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

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/acconfig/ltconfig

.include "../../mk/bsd.pkg.mk"
