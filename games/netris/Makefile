# $NetBSD: Makefile,v 1.1.1.1 2000/10/28 23:33:14 wiz Exp $
#

DISTNAME=		netris-0.5
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.netris.org/pub/netris/

MAINTAINER=		uebs@gmx.at
HOMEPAGE=		http://www.netris.org/

USE_GMAKE=		YES
HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./Configure

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/netris ${PREFIX}/bin
	@ ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/netris
	@ ${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/netris
	@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/netris
	@ ${INSTALL_DATA} ${WRKSRC}/robot_desc ${PREFIX}/share/doc/netris

.include "../../mk/bsd.pkg.mk"
