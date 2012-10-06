# $NetBSD: Makefile,v 1.20 2012/10/06 11:54:41 asau Exp $

DISTNAME=		medium
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Chess opening book for GNU Chess (medium)

DEPENDS+=		gnuchess>=5.07:../../games/gnuchess

CONFLICTS=		${CHESS_ENGINE}-book-*

WRKSRC=			${WRKDIR}
CHESS_ENGINE=		gnuchess
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		yes

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE:Q}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE:Q}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		book.txt
BOOK_FILE=		book.dat

do-build:
	@${ECHO} "book add ${PGN_FILE}" > ${WRKSRC}/makebook.gnuchess
	@${ECHO} "quit" >> ${WRKSRC}/makebook.gnuchess
	@cd ${WRKSRC} && ${CAT} makebook.gnuchess | ${PREFIX}/bin/gnuchess

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${DESTDIR}${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
