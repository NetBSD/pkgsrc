# $NetBSD: Makefile,v 1.16 2012/10/06 14:10:50 asau Exp $
#

DISTNAME=	fujiplay
PKGNAME=	fujiplay-1.33
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://topo.math.u-psud.fr/~bousch/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://topo.math.u-psud.fr/~bousch/fujiplay.html
COMMENT=	Download pictures from some Fujifilm digital cameras

DIST_SUBDIR=	fujiplay-1.33
WRKSRC=		${WRKDIR}

SUBST_CLASSES+=		cvsid
SUBST_MESSAGE.cvsid=	Removing CVS Ids from files.
SUBST_STAGE.cvsid=	post-extract
SUBST_SED.cvsid=	-e 's|\$$Id|Id|'
SUBST_SED.cvsid+=	-e 's| \$$$$||'
SUBST_FILES.cvsid=	fujiplay.c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fujiplay	${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/yycc2ppm	${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/fujiplay.lsm \
		${DESTDIR}${PREFIX}/share/doc/fujiplay
	${INSTALL_MAN} ${WRKSRC}/mx700-commands.html \
		${DESTDIR}${PREFIX}/share/doc/fujiplay

.include "../../mk/bsd.pkg.mk"
