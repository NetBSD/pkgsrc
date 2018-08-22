# $NetBSD: Makefile,v 1.13 2018/08/22 09:46:08 wiz Exp $
#

DISTNAME=		udpcast-20060619
PKGREVISION=		6
CATEGORIES=		net
MASTER_SITES=		http://www.udpcast.linux.lu/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.udpcast.linux.lu/
COMMENT=		Send data simultaneously to many destinations on a LAN

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake perl pod2man

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/udp-receiver ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/udp-sender ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/udp-receiver.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/udp-sender.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
