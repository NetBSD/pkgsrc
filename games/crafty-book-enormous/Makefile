# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 02:07:15 jlam Exp $

DISTNAME=		enormous
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
DISTFILES=		a${EXTRACT_SUFX}
DISTFILES+=		b${EXTRACT_SUFX}
DISTFILES+=		c${EXTRACT_SUFX}
DISTFILES+=		d${EXTRACT_SUFX}
DISTFILES+=		e${EXTRACT_SUFX}
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org

CONFLICTS=		${CHESS_ENGINE}-book-*

DEPENDS+=		crafty>=17.0:../../games/crafty

CHESS_ENGINE=		crafty
DIST_SUBDIR=		chessbooks
NO_WRKSUBDIR=		# defined
NO_CONFIGURE=		# defined

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		${DISTNAME}.pgn
BOOK_FILE=		book.bin

CRAFTYRC=		${WRKSRC}/.craftyrc

pre-extract:
	@${ECHO} ""
	@${ECHO} "  ** WARNING: This requires ~2.5GB of disk space to build."
	@${ECHO} ""

do-build:
        @${ECHO} ""
        @${ECHO} "  ** Get yourself a shower and a big mug of coffee,"
        @${ECHO} "  ** this will take _very_ long!"
        @${ECHO} ""

	${RM} -f ${PGN_FILE}
	cd ${WRKSRC} && ${CAT} ?.pgn > ${PGN_FILE}

	${RM} -f ${CRAFTYRC}
	${ECHO} "book create ${PGN_FILE} 60 3" > ${CRAFTYRC}
	${ECHO} "quit" >> ${CRAFTYRC}
	cd ${WRKSRC} && crafty bookpath=.

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
