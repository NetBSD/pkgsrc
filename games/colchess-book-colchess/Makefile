# $NetBSD: Makefile,v 1.1.1.1 2000/10/24 20:12:17 jlam Exp $

DISTNAME=		colchess
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}
WRKSRC=			${WRKDIR}/ColChess
CATEGORIES=		games
MASTER_SITES=		http://www.ast.cam.ac.uk/~cmf/chess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.ast.cam.ac.uk/~cmf/chess/

DEPENDS+=		colchess>=7.0:../../games/colchess

CONFLICTS+=		colchess-book-*

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
