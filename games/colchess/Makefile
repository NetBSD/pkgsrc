# $NetBSD: Makefile,v 1.6 2004/01/20 12:15:39 agc Exp $

DISTNAME=		colchess
PKGNAME=		${DISTNAME}-7.0
CATEGORIES=		games
MASTER_SITES=		http://www.ast.cam.ac.uk/~cmf/chess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.ast.cam.ac.uk/~cmf/chess/colchess/
COMMENT=		Chess analysis engine

WRKSRC=			${WRKDIR}/ColChess
DIST_SUBDIR=		${PKGNAME}
NO_CONFIGURE=		# defined
MAKE_ENV+=		PREFIX="${PREFIX}"

DATADIR=		${PREFIX}/share/colchess
DOCDIR=			${PREFIX}/share/doc/colchess

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colchess ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/chessdat.dat ${DATADIR}
	${INSTALL_DATA_DIR} ${DATADIR}/tests
	${INSTALL_DATA} ${WRKSRC}/tests/*.epd ${DATADIR}/tests
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
