# $NetBSD: Makefile,v 1.18 2014/09/11 17:08:00 jperkin Exp $

DISTNAME=		small
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20140911
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Chess opening book for EXchess (small)
LICENSE=		public-domain

DEPENDS+=		exchess-[0-9]*:../../games/exchess

CONFLICTS=		${CHESS_ENGINE}-book-medium-[0-9]*

WRKSRC=			${WRKDIR}
CHESS_ENGINE=		exchess
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		yes

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE:Q}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE:Q}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		${DISTNAME}.txt
BOOK_FILE=		open_bk.dat

CMDFILE=		${WRKSRC}/exchess.input

do-build:
	${RM} -f ${CMDFILE}
	${ECHO} "build" > ${CMDFILE}
	${ECHO} "${PGN_FILE}" >> ${CMDFILE}
	${ECHO} "n" >> ${CMDFILE}
	${ECHO} "60" >> ${CMDFILE}
	${ECHO} "3" >> ${CMDFILE}
	${ECHO} "${BOOK_FILE}" >> ${CMDFILE}
	${ECHO} "quit" >> ${CMDFILE}
	cd ${WRKSRC} && exchess < ${CMDFILE}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${DESTDIR}${BOOKDIR}

.include "../../mk/bsd.pkg.mk"
