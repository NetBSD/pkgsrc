# $NetBSD: Makefile,v 1.6 2001/09/27 23:18:07 jlam Exp $

DISTNAME=		medium
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org
COMMENT=		chess opening book for GNU Chess (medium)

DEPENDS+=		gnuchess>=5.00nb1:../../games/gnuchess

CONFLICTS=		${CHESS_ENGINE}-book-[0-9]*

CHESS_ENGINE=		gnuchess
DIST_SUBDIR=		chessbooks
WRKSRC=			${WRKDIR}
NO_CONFIGURE=		# defined

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		book.txt
BOOK_FILE=		book.dat

do-build:
	@${ECHO} ""
	@${ECHO} "  ** Go to bed!  This will take _very_ long!"
	@${ECHO} ""
	cd ${WRKSRC} && gnuchess compile ${PGN_FILE} ${BOOK_FILE}

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
