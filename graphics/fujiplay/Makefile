# $NetBSD: Makefile,v 1.8 2005/02/21 20:26:11 hubertf Exp $
#

DISTNAME=	fujiplay
PKGNAME=	fujiplay-1.33
CATEGORIES=	graphics
MASTER_SITES=	http://topo.math.u-psud.fr/~bousch/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://topo.math.u-psud.fr/~bousch/fujiplay.html
COMMENT=	Download pictures from some Fujifilm digital cameras

DIST_SUBDIR=	fujiplay-1.33
WRKSRC=		${WRKDIR}

post-patch:
	cd ${WRKSRC} ; ${MV} fujiplay.c fujiplay.c.orig2 ; \
	${SED} \
		-e '791,794s/^/"/g' \
		-e '791,793s/$$/\\n"/' \
		-e '790,790s/".*$$//' \
		<fujiplay.c.orig2 >fujiplay.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fujiplay	${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/yycc2ppm	${PREFIX}/bin
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/fujiplay.lsm ${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/mx700-commands.html ${PREFIX}/share/doc/fujiplay

.include "../../mk/bsd.pkg.mk"
