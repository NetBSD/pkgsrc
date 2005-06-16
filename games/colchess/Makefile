# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:53 jlam Exp $

DISTNAME=		colchess
PKGNAME=		${DISTNAME}-7.0
CATEGORIES=		games
MASTER_SITES=		http://www.ast.cam.ac.uk/~cmf/chess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ast.cam.ac.uk/~cmf/chess/colchess/
COMMENT=		Chess analysis engine

DIST_SUBDIR=		${PKGNAME}
MAKE_ENV+=		PREFIX="${PREFIX}"
NO_CONFIGURE=		# defined
WRKSRC=			${WRKDIR}/ColChess

DATADIR=		${PREFIX}/share/colchess
DOCDIR=			${PREFIX}/share/doc/colchess
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colchess ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/chessdat.dat ${DATADIR}
	${INSTALL_DATA_DIR} ${DATADIR}/tests
	${INSTALL_DATA} ${WRKSRC}/tests/*.epd ${DATADIR}/tests
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
