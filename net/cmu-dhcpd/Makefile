# $NetBSD: Makefile,v 1.6 2004/01/20 12:22:19 agc Exp $
#

DISTNAME=	CMU-dhcp-3.3.7+PU-9
PKGNAME=	cmu-dhcpd-3.3.7.9
CATEGORIES=	net
MASTER_SITES=	http://heymon.princeton.edu/software/dhcpd/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://heymon.princeton.edu/software/dhcpd/
COMMENT=	CMU BootP and DHCP server, plus Princeton patches

WRKSRC=		${WRKDIR}/CMU-dhcp-3.3.7+PU-9
GNU_CONFIGURE=	YES

do-install:
	${INSTALL_DATA_DIR} /var/db/bindings
	${INSTALL_PROGRAM} ${WRKSRC}/dhcpd ${PREFIX}/sbin/cmu-dhcpd
	${INSTALL_MAN} ${WRKSRC}/man/bootptab.5 ${PREFIX}/man/man5/bootptab.5
	${INSTALL_MAN} ${WRKSRC}/man/dhcpd.8 ${PREFIX}/man/man8/dhcpd.8
	${INSTALL_MAN} ${WRKSRC}/man/dhcpd.conf.5 ${PREFIX}/man/man5/dhcpd.conf.5

.include "../../mk/bsd.pkg.mk"
