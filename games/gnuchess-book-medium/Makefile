# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 01:57:43 jlam Exp $

DISTNAME=		medium
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org

CONFLICTS=		${CHESS_ENGINE}-book-*

DEPENDS+=		gnuchess>=5.00nb1:../../games/gnuchess

CHESS_ENGINE=		gnuchess
DIST_SUBDIR=		chessbooks
NO_WRKSUBDIR=		# defined
NO_CONFIGURE=		# defined

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		book.txt
BOOK_FILE=		book.dat

do-build:
	@${ECHO} ""
	@${ECHO} "  ** Get yourself a shower and a big mug of coffee,"
	@${ECHO} "  ** this will take _very_ long!"
	@${ECHO} ""
	cd ${WRKSRC} && gnuchess compile ${PGN_FILE} ${BOOK_FILE}

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
