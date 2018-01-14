# $NetBSD: Makefile,v 1.18 2018/01/14 15:26:46 rillig Exp $

DISTNAME=		colchess
PKGNAME=		${DISTNAME}-7.0
CATEGORIES=		games
MASTER_SITES=		http://www.ast.cam.ac.uk/~cmf/chess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.ast.cam.ac.uk/~cmf/chess/colchess/
COMMENT=		Chess analysis engine

DIST_SUBDIR=		${PKGNAME_NOREV}
MAKE_ENV+=		PREFIX=${PREFIX}
NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/ColChess

DATADIR=		${PREFIX}/share/colchess
DOCDIR=			${PREFIX}/share/doc/colchess
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colchess ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/chessdat.dat ${DESTDIR}${DATADIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}/tests
	${INSTALL_DATA} ${WRKSRC}/tests/*.epd ${DESTDIR}${DATADIR}/tests
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
