# $NetBSD: Makefile,v 1.4 2003/07/17 21:42:59 grant Exp $
#

DISTNAME=	viewfax-2.4
PKGREVISION=	1
CATEGORIES=	graphics comms
MASTER_SITES=	ftp://ftp.hylafax.org/pub/hylafax/contrib/viewfax/ \
		ftp://ftp.leo.org/pub/comp/networking/communication/modem/mgetty/ \
		ftp://ftp.tuwien.ac.at/infosys/fax/hylafax/contrib/viewfax/ \
		http://gd.tuwien.ac.at/infosys/fax/hylafax/contrib/viewfax/ \
		ftp://ftp.ips.gov.au/mirror/hylafax/contrib/viewfax/ \
		ftp://ftp.oce.nl/pub/gnu/hylafax/contrib/viewfax/ \
		ftp://ftp.rge.com/pub/communications/hylafax/contrib/viewfax/

MAINTAINER=	rh@NetBSD.org
COMMENT=	Tool for displaying fax files in an X Window

USE_IMAKE=	yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/viewfax

.include "../../mk/bsd.pkg.mk"
