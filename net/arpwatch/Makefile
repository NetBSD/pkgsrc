# $NetBSD: Makefile,v 1.1 1998/04/27 18:06:37 bouyer Exp $
#

DISTNAME=       arpwatch-2.0.2
CATEGORIES=	sysutils
MASTER_SITES=   ftp://ftp.ee.lbl.gov/
EXTRACT_SUFX=     .tar.Z

MAINTAINER=	bouyer@netbsd.org

GNU_CONFIGURE=	yes
MAN8=		arpwatch.8 arpsnmp.8

post-install:
	${INSTALL_MAN} ${WRKSRC}/arpwatch.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/arpsnmp.8 ${PREFIX}/man/man8
	@/bin/test -e /var/db/arpwatch || /bin/mkdir /var/db/arpwatch
	/usr/bin/touch /var/db/arpwatch/arp.dat
	${INSTALL_DATA} ${WRKSRC}/ethercodes.dat ${PREFIX}/etc

.include "../../mk/bsd.pkg.mk"
