# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:56 jlam Exp $
#

DISTNAME=	xpipeman-1.5
CATEGORIES=	games x11
MASTER_SITES=	http://www.spinne.com/x/games/xpipeman/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.spinne.com/x/games/xpipeman/
COMMENT=	Connect the pipes to contain the water flow game for X11

WRKSRC=		${WRKDIR}/xpipeman
USE_IMAKE=	yes

INSTALLATION_DIRS=	bin man/man6

do-install:
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xpipeman \
		${X11PREFIX}/bin/xpipeman
	${INSTALL_MAN} ${WRKSRC}/xpipeman.man ${X11PREFIX}/man/man6/xpipeman.6
	${INSTALL} -d -o bin -g games -m 0775 ${X11PREFIX}/share/xpipeman
	if [ ! -r /var/games/xpipescores ]; then \
		${INSTALL} -o bin -g games -m 0664 ${WRKSRC}/xpipescores /var/games ; \
	fi

.include "../../mk/bsd.pkg.mk"
