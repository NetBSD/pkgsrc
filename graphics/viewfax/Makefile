# $NetBSD: Makefile,v 1.10 2012/10/06 14:11:24 asau Exp $
#

DISTNAME=	viewfax-2.4
PKGREVISION=	2
CATEGORIES=	graphics comms
MASTER_SITES=	ftp://ftp.hylafax.org/pub/hylafax/contrib/viewfax/ \
		ftp://ftp.tuwien.ac.at/infosys/fax/hylafax/contrib/viewfax/ \
		http://gd.tuwien.ac.at/infosys/fax/hylafax/contrib/viewfax/ \
		ftp://ftp.ips.gov.au/mirror/hylafax/contrib/viewfax/ \
		ftp://ftp.oce.nl/pub/gnu/hylafax/contrib/viewfax/

MAINTAINER=	rh@NetBSD.org
COMMENT=	Tool for displaying fax files in an X Window

USE_IMAKE=	yes

INSTALLATION_DIRS=	libdata/viewfax

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
