# $NetBSD: Makefile,v 1.13 2001/08/24 11:37:07 abs Exp $
#

DISTNAME=	arpwatch-2.1a11
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/

MAINTAINER=	bouyer@netbsd.org
COMMENT=	monitor ARP activity on a network, maintaining a database

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
DEPENDS+=	libpcap>=0.4:../../net/libpcap
.endif

.include "../../mk/bsd.pkg.mk"
