# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 01:57:10 jlam Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/27 07:41:12 fenner Exp
#

DISTNAME=		chess-5.00
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}/book
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GNU:=chess/}

MAINTAINER=		jlam@netbsd.org

CONFLICTS+=		gnuchess-book-*

DEPENDS+=		gnuchess>=5.00nb1:../../games/gnuchess

CHESS_ENGINE=		gnuchess
NO_CONFIGURE=		# defined

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		book.pgn
BOOK_FILE=		book.dat

do-build:
	cd ${WRKSRC} && gnuchess compile ${PGN_FILE} ${BOOK_FILE}

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
