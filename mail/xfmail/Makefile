# $NetBSD: Makefile,v 1.12 2000/08/23 23:14:29 tron Exp $
#

DISTNAME=		xfmail-1.3
CATEGORIES=		mail x11
MASTER_SITES=		ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://Burka.NetVision.net.il/xfmail/xfmail.html

DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=		xforms-0.88:../../x11/xforms

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-sparc *-*-ns32k

RESTRICTED=		"Selling this software requires permission of the authors."
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_X11BASE=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES

post-install:
	${MKDIR} ${PREFIX}/share/doc/xfmail
	${INSTALL_DATA} ${WRKSRC}/Copyright ${PREFIX}/share/doc/xfmail

.include "../../mk/bsd.pkg.mk"
