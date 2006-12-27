# $NetBSD: Makefile,v 1.6 2006/12/27 13:37:38 joerg Exp $
#

DISTNAME=	viewfax-2.4
PKGREVISION=	2
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

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
