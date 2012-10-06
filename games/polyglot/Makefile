# $NetBSD: Makefile,v 1.5 2012/10/06 11:54:50 asau Exp $
#

DISTNAME=		polyglot_14
PKGNAME=		polyglot-1.4
CATEGORIES=		games
MASTER_SITES=		http://wbec-ridderkerk.nl/html/download/fruit/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wbec-ridderkerk.nl/html/details/PolyGlot.html
COMMENT=		UCI to WB adapter (for chess engines)

WRKSRC=			${WRKDIR}/polyglot_14
BUILD_DIRS=		src
MAKE_FILE=		${FILESDIR}/Makefile
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin share/doc/polyglot share/examples/polyglot

post-extract:
	cp ${FILESDIR}/fruit.ini ${WRKSRC}/

SUBST_CLASSES+=		ini
SUBST_STAGE.ini=	post-configure
SUBST_FILES.ini=	fruit.ini
SUBST_SED.ini=		-e 's,@LOCALBASE@,${LOCALBASE},g'

SRCS=		adapter.cpp attack.cpp board.cpp book.cpp book_make.cpp \
		book_merge.cpp colour.cpp engine.cpp epd.cpp fen.cpp	\
		game.cpp hash.cpp io.cpp line.cpp list.cpp main.cpp	\
		move.cpp move_do.cpp move_gen.cpp move_legal.cpp	\
		option.cpp parse.cpp pgn.cpp piece.cpp posix.cpp	\
		random.cpp san.cpp search.cpp square.cpp uci.cpp	\
		util.cpp

do-build:
	cd ${WRKSRC}/src && \
		${CXX} ${CXXFLAGS} ${LDFLAGS} -lm -o polyglot ${SRCS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/polyglot ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/polyglot/
	${INSTALL_DATA} ${WRKSRC}/fruit.ini \
		${DESTDIR}${PREFIX}/share/examples/polyglot/

.include "../../mk/bsd.pkg.mk"
