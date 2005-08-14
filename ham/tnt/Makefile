# $NetBSD: Makefile,v 1.21 2005/08/14 14:45:58 wulf Exp $
#

DISTNAME=	tnt-1.9.1
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	ftp://ftp.wspse.de/pub/packet_radio/tnt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://wspse.de/WSPse/Packet.php3
COMMENT=	Amateur packet radio terminal program for TNC2, AEA PK232 and PK88

DEPENDS+=	dialog>=0.6z:../../misc/dialog

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INFO_FILES=	tntdoc.info

.include "../../mk/bsd.pkg.mk"
