# $NetBSD: Makefile,v 1.1.1.1 2000/08/29 10:09:43 jdc Exp $

DISTNAME=		netmaze0.81
PKGNAME=		netmaze-0.81
CATEGORIES=		games
MASTER_SITES=  		${MASTER_SITE_XCONTRIB:=games/multiplayer/}

MAINTAINER=		jdc@netbsd.org

USE_IMAKE=		yes

WRKSRC=			${WRKDIR}/netmaze

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.bak
	${SED} -e 's|@X11LIBS@|-Wl,-R${X11BASE}/lib|g' \
		< ${WRKSRC}/Imakefile.bak > ${WRKSRC}/Imakefile

.include "../../mk/bsd.pkg.mk"
