# $NetBSD: Makefile,v 1.18 2013/04/06 03:45:21 rodent Exp $

DISTNAME=		pppoe.20000912
PKGNAME=		mouse-${DISTNAME:S/./-/}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://sparkle.rodents.montreal.qc.ca/pub/mouse/ftp.netbsd.org/pppoe/

MAINTAINER=		mouse@NetBSD.org
COMMENT=		PPP over Ethernet program by der Mouse

NOT_FOR_PLATFORM=	Interix-*-* # no userland protocol stack support

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	sbin share/doc/mouse_pppoe

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -o pppoe pppoe.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pppoe ${DESTDIR}${PREFIX}/sbin/mouse-pppoe
	${INSTALL_DATA} ${WRKSRC}/pppoe.readme ${DESTDIR}${PREFIX}/share/doc/mouse_pppoe

.include "../../mk/bsd.pkg.mk"
