# $NetBSD: Makefile,v 1.9 2004/04/24 22:46:10 jlam Exp $

DISTNAME=		colchess
PKGNAME=		${CHESS_ENGINE}-book-${DIST_SUBDIR}
CATEGORIES=		games
MASTER_SITES=		http://www.ast.cam.ac.uk/~cmf/chess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ast.cam.ac.uk/~cmf/chess/colchess/
COMMENT=		Chess opening book for ColChess (default)

DEPENDS+=		colchess>=7.0:../../games/colchess

CONFLICTS+=		colchess-book-[0-9]*

WRKSRC=			${WRKDIR}/ColChess
CHESS_ENGINE=		colchess
DIST_SUBDIR=		colchess-7.0
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/share/${CHESS_ENGINE}
BOOK_FILE=		book.dat

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
