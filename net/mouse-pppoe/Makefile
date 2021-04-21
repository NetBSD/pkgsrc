# $NetBSD: Makefile,v 1.20 2021/04/21 09:19:08 wiz Exp $

DISTNAME=		pppoe.20000912
PKGNAME=		mouse-${DISTNAME:S/./-/}
PKGREVISION=		1
CATEGORIES=		net
#MASTER_SITES=		ftp://sparkle.rodents.montreal.qc.ca/pub/mouse/ftp.netbsd.org/pppoe/

MAINTAINER=		mouse@NetBSD.org
COMMENT=		PPP over Ethernet program by der Mouse

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	sbin share/doc/mouse_pppoe

do-build:
	(cd ${WRKSRC} ; ${CC} ${CFLAGS} -o pppoe pppoe.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pppoe ${DESTDIR}${PREFIX}/sbin/mouse-pppoe
	${INSTALL_DATA} ${WRKSRC}/pppoe.readme ${DESTDIR}${PREFIX}/share/doc/mouse_pppoe

.include "../../mk/bsd.pkg.mk"
