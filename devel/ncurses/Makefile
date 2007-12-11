# $NetBSD: Makefile,v 1.81 2007/12/11 05:27:05 bjs Exp $

.include "Makefile.common"
PKGREVISION=	2

COMMENT=	CRT screen handling and optimization package

INSTALLATION_DIRS+=	share/examples

.if ${OPSYS} == "SunOS"
# misc/screen  installs screen, screen-bce and screen-s
# so we need to remove these  here to avoid a conflict.
# this means we also remove the entries which have a
# use=screen in them
SUBST_CLASSES+=		ti
SUBST_STAGE.ti=		post-configure
SUBST_MESSAGE.ti=	Removing screen entries from the terminfo database.
SUBST_FILES.ti=		${TERMINFO_SRC}
# see misc/screen/PLIST for these:
SUBST_SED.ti=		-e '/^screen|/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen-bce|/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen-s|/,/^$$/d'
# see ${TERMINFO_SRC} and look for use=screen for these
SUBST_SED.ti+=		-e '/^screen.teraterm|/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen.linux|/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen-w|/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen-16color/,/^$$/d'
SUBST_SED.ti+=		-e '/^screen-256color/,/^$$/d'
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
