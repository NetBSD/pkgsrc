# $NetBSD: Makefile,v 1.11 2005/12/05 20:50:15 rillig Exp $

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
NO_CONFIGURE=		yes
NO_BUILD=		yes

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE:Q}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE:Q}

BOOKDIR=		${PREFIX}/share/${CHESS_ENGINE}
BOOK_FILE=		book.dat

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
