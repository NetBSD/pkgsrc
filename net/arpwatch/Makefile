# $NetBSD: Makefile,v 1.4 1998/06/22 12:58:33 agc Exp $
#

DISTNAME=	arpwatch-2.0.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	bouyer@netbsd.org

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/arpwatch.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/arpsnmp.8 ${PREFIX}/man/man8
	@/bin/test -e /var/db/arpwatch || ${MKDIR} /var/db/arpwatch
	${TOUCH} /var/db/arpwatch/arp.dat
	${INSTALL_DATA} ${WRKSRC}/ethercodes.dat ${PREFIX}/etc

.include "../../mk/bsd.pkg.mk"
