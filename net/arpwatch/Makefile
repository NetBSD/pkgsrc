# $NetBSD: Makefile,v 1.17 2003/07/17 22:51:00 grant Exp $
#

DISTNAME=	arpwatch-2.1a11
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/

MAINTAINER=	bouyer@NetBSD.org
COMMENT=	monitor ARP activity on a network, maintaining a database

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

pre-patch:
	f=arpwatch.h;							\
	${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f-prepatch;			\
	${SED} -e '/Header/s|\$$||g' ${WRKSRC}/$$f-prepatch > ${WRKSRC}/$$f

post-install:
	${INSTALL_MAN} ${WRKSRC}/arpwatch.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/arpsnmp.8 ${PREFIX}/man/man8
	@${INSTALL_DATA_DIR} /var/db/arpwatch
	${TOUCH} /var/db/arpwatch/arp.dat
	${INSTALL_DATA} ${WRKSRC}/ethercodes.dat ${PREFIX}/etc

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
