# $NetBSD: Makefile,v 1.13 2004/04/24 22:46:10 jlam Exp $

DISTNAME=		medium
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Chess opening book for GNU Chess (medium)

DEPENDS+=		gnuchess>=5.07:../../games/gnuchess

CONFLICTS=		${CHESS_ENGINE}-book-*

WRKSRC=			${WRKDIR}
CHESS_ENGINE=		gnuchess
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		# defined

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		book.txt
BOOK_FILE=		book.dat

do-build:
	@${ECHO} "book add ${PGN_FILE}" > ${WRKSRC}/makebook.gnuchess
	@${ECHO} "quit" >> ${WRKSRC}/makebook.gnuchess
	@cd ${WRKSRC} && ${CAT} makebook.gnuchess | ${PREFIX}/bin/gnuchess 

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
