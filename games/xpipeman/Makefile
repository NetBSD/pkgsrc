# $NetBSD: Makefile,v 1.3 1998/09/14 23:52:17 garbled Exp $
#

DISTNAME=	xpipeman-1.5
CATEGORIES=	games x11
MASTER_SITES=	http://www.spinne.com/x/games/xpipeman/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.spinne.com/x/games/xpipeman/

WRKSRC=		${WRKDIR}/xpipeman

USE_IMAKE=	yes

do-install:
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xpipeman \
		${X11BASE}/bin/xpipeman
	${INSTALL_MAN} ${WRKSRC}/xpipeman.man ${X11BASE}/man/man6/xpipeman.6
	${INSTALL} -d -o bin -g games -m 0775 ${X11BASE}/share/xpipeman
	if [ ! -e /var/games/xpipescores ]; then \
		${INSTALL} -o bin -g games -m 0664 ${WRKSRC}/xpipescores /var/games ; \
	fi

.include "../../mk/bsd.pkg.mk"
