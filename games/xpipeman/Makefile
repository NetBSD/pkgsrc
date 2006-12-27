# $NetBSD: Makefile,v 1.14 2006/12/27 13:37:37 joerg Exp $
#

DISTNAME=	xpipeman-1.5
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/strategy/}

MAINTAINER=	root@garbled.net
# HOMEPAGE=	http://www.spinne.com/x/games/xpipeman/
# domain squatted, page last updated 1999
COMMENT=	Connect the pipes to contain the water flow game for X11

WRKSRC=		${WRKDIR}/xpipeman
USE_IMAKE=	yes

INSTALLATION_DIRS=	bin man/man6

do-install:
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xpipeman \
		${PREFIX}/bin/xpipeman
	${INSTALL_MAN} ${WRKSRC}/xpipeman.man ${PREFIX}/man/man6/xpipeman.6
	${INSTALL} -d -o bin -g games -m 0775 ${PREFIX}/share/xpipeman
	if [ ! -r /var/games/xpipescores ]; then \
		${INSTALL} -o bin -g games -m 0664 ${WRKSRC}/xpipescores /var/games ; \
	fi

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
