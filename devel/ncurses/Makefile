# $NetBSD: Makefile,v 1.75 2007/01/08 11:01:05 adam Exp $

.include "Makefile.common"

COMMENT=	CRT screen handling and optimization package

INSTALLATION_DIRS=	share/examples

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		ti
SUBST_STAGE.ti=		post-configure
SUBST_MESSAGE.ti=	Removing screen entries from the terminfo database.
SUBST_FILES.ti=		${TERMINFO_SRC}
SUBST_SED.ti=		-e '/^screen|/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen-w|/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen.teraterm|/,/^$$/d'
.endif

post-configure:
	cd ${WRKSRC}/man;					\
	for f in *.1m; do					\
		mv -f $${f} `${BASENAME} $${f} .1m`.1; 	\
	done;							\
	for f in *.3x; do					\
		mv -f $${f} `${BASENAME} $${f} .3x`.3; 	\
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/c++/demo.cc \
		${DESTDIR}${PREFIX}/share/examples/ncurses++demo.cc

.include "../../mk/bsd.pkg.mk"
