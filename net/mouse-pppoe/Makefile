# $NetBSD: Makefile,v 1.15 2008/10/02 17:01:16 joerg Exp $

DISTNAME=		pppoe.20000912
PKGNAME=		mouse-${DISTNAME:S/./-/}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/mouse/pppoe/

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=		mouse@NetBSD.org
COMMENT=		derMouse's PPP over Ethernet program

NOT_FOR_PLATFORM=	Interix-*-* # no userland protocol stack support

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	sbin share/doc/mouse_pppoe

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -o pppoe pppoe.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pppoe ${DESTDIR}${PREFIX}/sbin/mouse-pppoe
	${INSTALL_DATA} ${WRKSRC}/pppoe.readme ${DESTDIR}${PREFIX}/share/doc/mouse_pppoe

.include "../../mk/bsd.pkg.mk"
