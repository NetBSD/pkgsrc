# $NetBSD: Makefile,v 1.2 2006/08/22 15:52:15 joerg Exp $
#

DISTNAME=		udpcast-20060619
CATEGORIES=		net
MASTER_SITES=		http://udpcast.linux.lu/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://udpcast.linux.lu/
COMMENT=		Send data simultaneously to many destinations on a LAN

USE_TOOLS+=		gmake perl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/udp-receiver ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/udp-sender ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/udp-receiver.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/udp-sender.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
