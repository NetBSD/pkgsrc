# $NetBSD: Makefile,v 1.12 2004/01/20 12:15:40 agc Exp $

DISTNAME=		enormous
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip
DISTFILES=		a${EXTRACT_SUFX}
DISTFILES+=		b${EXTRACT_SUFX}
DISTFILES+=		c${EXTRACT_SUFX}
DISTFILES+=		d${EXTRACT_SUFX}
DISTFILES+=		e${EXTRACT_SUFX}

MAINTAINER=		jlam@NetBSD.org
COMMENT=		Chess opening book for Crafty (enormous)

DEPENDS+=		crafty>=17.0:../../games/crafty

CONFLICTS=		${CHESS_ENGINE}-book-[0-9]*

REASON=			"Files too large"
NO_SRC_ON_CDROM=	${REASON}
NO_SRC_ON_FTP=		${REASON}

WRKSRC=			${WRKDIR}
CHESS_ENGINE=		crafty
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		# defined

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		${DISTNAME}.pgn
BOOK_FILE=		book.bin

CRAFTYRC=		${WRKSRC}/.craftyrc

pre-extract:
	@${ECHO} ""
	@${ECHO} "  ** WARNING: This requires ~3GB of disk space to build."
	@${ECHO} ""

do-build:
	@${ECHO} ""
	@${ECHO} "  ** Get yourself a shower and a big mug of coffee,"
	@${ECHO} "  ** this will take _very_ long!"
	@${ECHO} ""

	${RM} -f ${PGN_FILE}
	cd ${WRKSRC} && ${CAT} ?.pgn > ${PGN_FILE}

	${RM} -f ${CRAFTYRC}
	${ECHO} "book create ${PGN_FILE} 60 10 50" > ${CRAFTYRC}
	${ECHO} "quit" >> ${CRAFTYRC}
	cd ${WRKSRC} && crafty bookpath=.

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
