# $NetBSD: Makefile,v 1.13 2006/02/05 23:09:13 joerg Exp $

DISTNAME=		medium
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Chess opening book for Crafty (medium)

DEPENDS+=		crafty>=17.0:../../games/crafty

CONFLICTS=		${CHESS_ENGINE}-book-[0-9]*

WRKSRC=			${WRKDIR}
CHESS_ENGINE=		crafty
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		yes

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE:Q}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE:Q}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		book.txt
BOOK_FILE=		book.bin

CRAFTYRC=		${WRKSRC}/.craftyrc

do-build:
	${RM} -f ${CRAFTYRC}
	${ECHO} "book create ${PGN_FILE} 60 3" > ${CRAFTYRC}
	${ECHO} "quit" >> ${CRAFTYRC}
	cd ${WRKSRC} && crafty bookpath=.

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
