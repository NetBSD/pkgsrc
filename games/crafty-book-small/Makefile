# $NetBSD: Makefile,v 1.15 2008/03/04 06:59:03 jlam Exp $

DISTNAME=		small
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Chess opening book for Crafty (small)

DEPENDS+=		crafty>=17.0:../../games/crafty

CONFLICTS=		${CHESS_ENGINE}-book-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
CHESS_ENGINE=		crafty
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		yes

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE:Q}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE:Q}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		${DISTNAME}.txt
BOOK_FILE=		book.bin

CRAFTYRC=		${WRKSRC}/.craftyrc

do-build:
	${RM} -f ${CRAFTYRC}
	${ECHO} "book create ${PGN_FILE} 60 3" > ${CRAFTYRC}
	${ECHO} "quit" >> ${CRAFTYRC}
	cd ${WRKSRC} && crafty bookpath=.

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${DESTDIR}${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
