# $NetBSD: Makefile,v 1.15 2001/02/17 18:25:10 wiz Exp $
#

DISTNAME=		xfmail-1.3
CATEGORIES=		mail x11
MASTER_SITES=		ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://Burka.NetVision.net.il/xfmail/xfmail.html
COMMENT=		Xforms based mail application for Unix operating systems

DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=		xforms>=0.88nb1:../../x11/xforms

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-sparc NetBSD-*-powerpc

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
