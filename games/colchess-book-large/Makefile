# $NetBSD: Makefile,v 1.1.1.1 2000/10/24 20:13:14 jlam Exp $

DISTNAME=		book_large
PKGNAME=		${CHESS_ENGINE}-book-large-20000512
CATEGORIES=		games
MASTER_SITES=		http://www.ast.cam.ac.uk/~cmf/chess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jlam@netbsd.org

DEPENDS+=		colchess>=7.0:../../games/colchess

CONFLICTS=		${CHESS_ENGINE}-book-*

CHESS_ENGINE=		colchess
DIST_SUBDIR=		chessbooks
NO_WRKSUBDIR=		# defined
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
