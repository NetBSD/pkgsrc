# $NetBSD: Makefile,v 1.11 2004/01/20 12:15:40 agc Exp $

DISTNAME=		medium
PKGNAME=		${CHESS_ENGINE}-book-${DISTNAME}-20000511
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/common/${DISTNAME}/
EXTRACT_SUFX=		.zip

MAINTAINER=		jlam@NetBSD.org
COMMENT=		Chess opening book for GNU Chess (medium)

DEPENDS+=		gnuchess>=5.00nb1:../../games/gnuchess

CONFLICTS=		${CHESS_ENGINE}-book-[0-9]*

WRKSRC=			${WRKDIR}
CHESS_ENGINE=		gnuchess
DIST_SUBDIR=		chessbooks
NO_CONFIGURE=		# defined
USE_PERL5=		build
USE_BUILDLINK2=		YES

PLIST_SUBST+=		CHESS_ENGINE=${CHESS_ENGINE}
PLIST_SUBST+=		BOOK_FILE=${BOOK_FILE}

BOOKDIR=		${PREFIX}/lib/${CHESS_ENGINE}
PGN_FILE=		book.txt
PGN_CONVERTED_FILE=	book_pgn.txt
BOOK_FILE=		book.dat

do-build:
	@${ECHO} ""
	@${ECHO} "  ** Go to bed!  This will take _very_ long!"
	@${ECHO} ""
	${PREFIX}/bin/perl ${PKGDIR}/files/convert.pl < ${WRKSRC}/${PGN_FILE} > ${WRKSRC}/${PGN_CONVERTED_FILE}
	cd ${WRKSRC} && gnuchess compile ${PGN_CONVERTED_FILE} ${BOOK_FILE}

do-install:
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${INSTALL_DATA} ${WRKSRC}/${BOOK_FILE} ${BOOKDIR}

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
