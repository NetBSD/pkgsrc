# $NetBSD: Makefile,v 1.6 2001/02/27 17:41:05 hubertf Exp $

DISTNAME=		pppoe.20000912
PKGNAME=		mouse-${DISTNAME:S/./-/}nb1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/misc/mouse/pppoe/

MAINTAINER=		mouse@netbsd.org
COMMENT=		derMouse's PPP over Ethernet program

NO_WRKSUBDIR=		yes

do-build:
	(cd ${WRKSRC} ; ${CC} -O2 -o pppoe pppoe.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pppoe ${PREFIX}/sbin/mouse-pppoe
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mouse_pppoe
	${INSTALL_DATA} ${WRKSRC}/pppoe.readme ${PREFIX}/share/doc/mouse_pppoe

.include "../../mk/bsd.pkg.mk"
