# $NetBSD: Makefile,v 1.9 2004/04/24 22:46:10 jlam Exp $

DISTNAME=		book_large
PKGNAME=		${CHESS_ENGINE}-book-large-20000512
CATEGORIES=		games
MASTER_SITES=		http://www.ast.cam.ac.uk/~cmf/chess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Chess opening book for ColChess (large)

DEPENDS+=		colchess>=7.0:../../games/colchess

CONFLICTS=		${CHESS_ENGINE}-book-[0-9]*

WRKSRC=			${WRKDIR}
CHESS_ENGINE=		colchess
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		# defined

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/share/${CHESS_ENGINE}
BOOK_FILE=		book.dat

do-build:
	cd ${WRKSRC}; ${LN} ${DISTNAME}.dat ${BOOK_FILE}

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
