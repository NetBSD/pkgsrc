# $NetBSD: Makefile,v 1.3 2008/04/07 18:19:22 joerg Exp $
#

DISTNAME=		udpcast-20060619
CATEGORIES=		net
MASTER_SITES=		http://udpcast.linux.lu/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://udpcast.linux.lu/
COMMENT=		Send data simultaneously to many destinations on a LAN

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/udp-receiver ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/udp-sender ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/udp-receiver.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/udp-sender.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
