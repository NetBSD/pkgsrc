# $NetBSD: Makefile,v 1.2 2002/03/18 20:24:06 wiz Exp $
#

DISTNAME=	xtris-1.15
CATEGORIES=	games x11
MASTER_SITES=	http://www.iagora.com/~espel/xtris/

MAINTAINER=	opp@MuFFiN.Org
HOMEPAGE=	http://www.iagora.com/~espel/xtris/
COMMENT=	Multi-player version of a popular game for the X Window system

WRKSRC=		${WRKDIR}/xtris
USE_X11=	yes
USE_X11BASE=	yes

BUILD_DEFS+=	USE_INET6

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
CFLAGS+=	-DINET6
.endif

do-install:
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xtris ${PREFIX}/bin/xtris
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xtbot ${PREFIX}/bin/xtbot
	${INSTALL} -o bin -g games -m 2755 ${WRKSRC}/xtserv ${PREFIX}/bin/xtserv
	${INSTALL_MAN} ${WRKSRC}/xtris.6 ${PREFIX}/man/man6/xtris.6
	${INSTALL_MAN} ${WRKSRC}/xtbot.6 ${PREFIX}/man/man6/xtbot.6
	${INSTALL_MAN} ${WRKSRC}/xtserv.6 ${PREFIX}/man/man6/xtserv.6

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
