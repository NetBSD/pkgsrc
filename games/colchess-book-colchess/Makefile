# $NetBSD: Makefile,v 1.5 2002/10/27 17:20:29 cjep Exp $

DISTNAME=		colchess
PKGNAME=		${CHESS_ENGINE}-book-${DIST_SUBDIR}
WRKSRC=			${WRKDIR}/ColChess
CATEGORIES=		games
MASTER_SITES=		http://www.ast.cam.ac.uk/~cmf/chess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.ast.cam.ac.uk/~cmf/chess/colchess/
COMMENT=		chess opening book for ColChess (default)

DEPENDS+=		colchess>=7.0:../../games/colchess

CONFLICTS+=		colchess-book-[0-9]*

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
