# $NetBSD: Makefile,v 1.15 2017/08/01 17:40:11 wiz Exp $

DISTNAME=		colchess
PKGNAME=		${CHESS_ENGINE}-book-${DIST_SUBDIR}
CATEGORIES=		games
MASTER_SITES=		http://www.ast.cam.ac.uk/~cmf/chess/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.ast.cam.ac.uk/~cmf/chess/colchess/
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
	${INSTALL_DATA_DIR} ${DESTDIR}${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${DESTDIR}${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
