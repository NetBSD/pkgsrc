# $NetBSD: Makefile,v 1.5 2003/07/17 21:40:37 grant Exp $
#

DISTNAME=	fujiplay
PKGNAME=	fujiplay-1.33
WRKSRC=		${WRKDIR}
CATEGORIES=	graphics
MASTER_SITES=	http://topo.math.u-psud.fr/~bousch/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://topo.math.u-psud.fr/~bousch/fujiplay.html
COMMENT=	Download pictures from some Fujifilm digital cameras

DIST_SUBDIR=	fujiplay-1.33

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fujiplay	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/yycc2ppm	${PREFIX}/bin
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/fujiplay.lsm ${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/mx700-commands.html ${PREFIX}/share/doc/fujiplay

.include "../../mk/bsd.pkg.mk"
