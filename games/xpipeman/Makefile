# $NetBSD: Makefile,v 1.1 1998/08/01 14:52:45 frueauf Exp $
#

DISTNAME=	xpipeman-1.5
CATEGORIES=	games x11
MASTER_SITES=	http://www.spinne.com/x/games/xpipeman/

MAINTAINER=	root@garbled.net

WRKSRC=		${WRKDIR}/xpipeman

USE_IMAKE=	yes

do-install:
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xpipeman \
		${X11BASE}/bin/xpipeman
	${INSTALL_MAN} ${WRKSRC}/xpipeman.man ${X11BASE}/man/man6/xpipeman.6
	${INSTALL} -d -o bin -g games -m 0775 ${X11BASE}/share/xpipeman
	${INSTALL} -o bin -g games -m 0664 ${WRKSRC}/xpipescores \
		${X11BASE}/share/xpipeman

.include "../../mk/bsd.pkg.mk"
