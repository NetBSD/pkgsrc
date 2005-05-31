# $NetBSD: Makefile,v 1.9 2005/05/31 21:47:34 wiz Exp $
#

DISTNAME=	xtris-1.15
CATEGORIES=	games x11
MASTER_SITES=	http://www.iagora.com/~espel/xtris/

MAINTAINER=	opp@MuFFiN.Org
HOMEPAGE=	http://www.iagora.com/~espel/xtris/xtris.html
COMMENT=	Multi-player version of a popular game for the X Window system

WRKSRC=		${WRKDIR}/xtris
USE_X11BASE=	yes

.include "options.mk"

do-install:
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xtris ${PREFIX}/bin/xtris
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xtbot ${PREFIX}/bin/xtbot
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xtserv ${PREFIX}/bin/xtserv
	${INSTALL_MAN} ${WRKSRC}/xtris.6 ${PREFIX}/man/man6/xtris.6
	${INSTALL_MAN} ${WRKSRC}/xtbot.6 ${PREFIX}/man/man6/xtbot.6
	${INSTALL_MAN} ${WRKSRC}/xtserv.6 ${PREFIX}/man/man6/xtserv.6

.include "../../mk/bsd.pkg.mk"
