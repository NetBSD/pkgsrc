# $NetBSD: Makefile,v 1.1.1.1 1999/11/23 04:22:13 hubertf Exp $
#

DISTNAME=	fujiplay
PKGNAME=	fujiplay-1.33
CATEGORIES=	graphics
MASTER_SITES=	http://topo.math.u-psud.fr/~bousch/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://topo.math.u-psud.fr/~bousch/fujiplay.html

NO_WRKSUBDIR=	yes
DIST_SUBDIR=	fujiplay-1.33

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fujiplay	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/yycc2ppm	${PREFIX}/bin
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/fujiplay.lsm ${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/mx700-commands.html ${PREFIX}/share/doc/fujiplay

.include "../../mk/bsd.pkg.mk"
