# $NetBSD: Makefile,v 1.13 2003/08/07 11:42:25 seb Exp $
#

DISTNAME=	tnt-1.9.1
CATEGORIES=	ham
MASTER_SITES=	ftp://excelsior.kullen.rwth-aachen.de/pub/packet_radio/tnt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://excelsior.kullen.rwth-aachen.de/
COMMENT=	Amateur packet radio terminal program for TNC2, AEA PK232 and PK88

DEPENDS+=	dialog>=0.6z:../../misc/dialog

USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_NEW_TEXINFO=	YES
INFO_FILES=	tntdoc.info

.include "../../mk/bsd.pkg.mk"
