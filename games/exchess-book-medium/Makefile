# $NetBSD: Makefile,v 1.15 2012/09/08 23:05:03 cheusov Exp $

DISTNAME=		medium
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Chess opening book for EXchess (medium)

DEPENDS+=		exchess-[0-9]*:../../games/exchess

CONFLICTS=		${CHESS_ENGINE}-book-small-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
CHESS_ENGINE=		exchess
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		yes

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE:Q}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE:Q}

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
	${INSTALL_DATA_DIR} ${DESTDIR}${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${DESTDIR}${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
