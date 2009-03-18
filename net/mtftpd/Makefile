# $NetBSD: Makefile,v 1.2 2009/03/18 13:29:32 jmcneill Exp $

DISTNAME=		mtftpd-20080229
CATEGORIES=		net
MASTER_SITES=		http://www.invisible.ca/~jmcneill/netbsd/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Open-loop multicast TFTP server

WRKSRC=			${WRKDIR}/mtftpd

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-DPKG_SYSCONFDIR=\"${PKG_SYSCONFDIR}\"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mtftpd
	${INSTALL_DATA} ${WRKSRC}/mtftpd.plist ${PREFIX}/share/examples/mtftpd

.include "../../mk/bsd.pkg.mk"
