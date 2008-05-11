# $NetBSD: Makefile,v 1.1.1.1 2008/05/11 20:27:04 jmcneill Exp $

DISTNAME=		mtftpd-20080229
CATEGORIES=		net
MASTER_SITES=		http://www.invisible.ca/~jmcneill/netbsd/

MAINTAINER=		jmcneill@invisible.ca
COMMENT=		Open-loop multicast TFTP server

WRKSRC=			${WRKDIR}/mtftpd

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-DPKG_SYSCONFDIR=\"${PKG_SYSCONFDIR}\"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mtftpd
	${INSTALL_DATA} ${WRKSRC}/mtftpd.plist ${PREFIX}/share/examples/mtftpd

.include "../../mk/bsd.pkg.mk"
