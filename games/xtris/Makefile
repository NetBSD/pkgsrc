# $NetBSD: Makefile,v 1.13 2006/06/25 07:28:05 rillig Exp $
#

DISTNAME=	xtris-1.15
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.iagora.com/~espel/xtris/

MAINTAINER=	opp@MuFFiN.Org
HOMEPAGE=	http://www.iagora.com/~espel/xtris/xtris.html
COMMENT=	Multi-player version of a popular game for the X Window system

WRKSRC=		${WRKDIR}/xtris
USE_X11BASE=	yes

.include "options.mk"

INSTALLATION_DIRS=	bin man/man6

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_GAME} ${WRKSRC}/xtris ${PREFIX}/bin/xtris
	${INSTALL_GAME} ${WRKSRC}/xtbot ${PREFIX}/bin/xtbot
	${INSTALL_GAME} ${WRKSRC}/xtserv ${PREFIX}/bin/xtserv
	${INSTALL_MAN} ${WRKSRC}/xtris.6 ${PREFIX}/man/man6/xtris.6
	${INSTALL_MAN} ${WRKSRC}/xtbot.6 ${PREFIX}/man/man6/xtbot.6
	${INSTALL_MAN} ${WRKSRC}/xtserv.6 ${PREFIX}/man/man6/xtserv.6

.include "../../mk/bsd.pkg.mk"
