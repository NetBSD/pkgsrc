# $NetBSD: Makefile,v 1.3 2010/02/11 22:10:59 joerg Exp $

DISTNAME=		mtftpd-20080229
CATEGORIES=		net
MASTER_SITES=		http://www.invisible.ca/~jmcneill/netbsd/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Open-loop multicast TFTP server

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/mtftpd

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-DPKG_SYSCONFDIR=\"${PKG_SYSCONFDIR}\"

INSTALLATION_DIRS+=	bin share/examples/mtftpd

post-install:
	${INSTALL_DATA} ${WRKSRC}/mtftpd.plist ${DESTDIR}${PREFIX}/share/examples/mtftpd

.include "../../mk/bsd.pkg.mk"
