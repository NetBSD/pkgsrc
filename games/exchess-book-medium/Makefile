# $NetBSD: Makefile,v 1.1.1.1 2000/10/25 08:40:38 jlam Exp $

DISTNAME=		medium
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@netbsd.org

DEPENDS+=		exchess-[0-9]*:../../games/exchess

CONFLICTS=		${CHESS_ENGINE}-book-*

CHESS_ENGINE=		exchess
DIST_SUBDIR=		chessbooks
NO_WRKSUBDIR=		# defined
NO_CONFIGURE=		# defined

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		book.txt
BOOK_FILE=		open_bk.dat

CMDFILE=		${WRKSRC}/exchess.input

do-build:
	@${ECHO} ""
	@${ECHO} "  ** Get yourself a shower and a big mug of coffee,"
	@${ECHO} "  ** this will take _very_ long!"
	@${ECHO} ""
	${RM} -f ${CMDFILE}
	${ECHO} "build" > ${CMDFILE}
	${ECHO} "${PGN_FILE}" >> ${CMDFILE}
	${ECHO} "60" >> ${CMDFILE}
	${ECHO} "3" >> ${CMDFILE}
	${ECHO} "${BOOK_FILE}" >> ${CMDFILE}
	${ECHO} "quit" >> ${CMDFILE}
	cd ${WRKSRC} && exchess < ${CMDFILE}

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
