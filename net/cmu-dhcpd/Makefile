# $NetBSD: Makefile,v 1.8 2005/11/08 15:32:43 tv Exp $
#

DISTNAME=	CMU-dhcp-3.3.7+PU-9
PKGNAME=	cmu-dhcpd-3.3.7.9
CATEGORIES=	net
MASTER_SITES=	http://heymon.princeton.edu/software/dhcpd/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://heymon.princeton.edu/software/dhcpd/
COMMENT=	CMU BootP and DHCP server, plus Princeton patches

NOT_FOR_PLATFORM=	Interix-*-* # no userland routing table support

WRKSRC=		${WRKDIR}/CMU-dhcp-3.3.7+PU-9
GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	man/man5 man/man8 sbin

do-install:
	${INSTALL_DATA_DIR} /var/db/bindings
	${INSTALL_PROGRAM} ${WRKSRC}/dhcpd ${PREFIX}/sbin/cmu-dhcpd
	${INSTALL_MAN} ${WRKSRC}/man/bootptab.5 ${PREFIX}/man/man5/bootptab.5
	${INSTALL_MAN} ${WRKSRC}/man/dhcpd.8 ${PREFIX}/man/man8/dhcpd.8
	${INSTALL_MAN} ${WRKSRC}/man/dhcpd.conf.5 ${PREFIX}/man/man5/dhcpd.conf.5

.include "../../mk/bsd.pkg.mk"
