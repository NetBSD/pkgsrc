# $NetBSD: Makefile,v 1.18 2004/08/02 21:32:12 minskim Exp $
#

DISTNAME=	tnt-1.9.1
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	ftp://excelsior.kullen.rwth-aachen.de/pub/packet_radio/tnt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://excelsior.kullen.rwth-aachen.de/
COMMENT=	Amateur packet radio terminal program for TNC2, AEA PK232 and PK88

DEPENDS+=	dialog>=0.6z:../../misc/dialog

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INFO_FILES=	tntdoc.info

.include "../../mk/bsd.pkg.mk"
