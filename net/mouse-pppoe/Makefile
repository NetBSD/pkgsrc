# $NetBSD: Makefile,v 1.14 2005/11/07 21:39:28 tv Exp $

DISTNAME=		pppoe.20000912
PKGNAME=		mouse-${DISTNAME:S/./-/}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/mouse/pppoe/

MAINTAINER=		mouse@NetBSD.org
COMMENT=		derMouse's PPP over Ethernet program

NOT_FOR_PLATFORM=	Interix-*-* # no userland protocol stack support

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	sbin

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -o pppoe pppoe.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pppoe ${PREFIX}/sbin/mouse-pppoe
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mouse_pppoe
	${INSTALL_DATA} ${WRKSRC}/pppoe.readme ${PREFIX}/share/doc/mouse_pppoe

.include "../../mk/bsd.pkg.mk"
