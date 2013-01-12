# $NetBSD: Makefile,v 1.17 2013/01/12 19:07:55 is Exp $
#

DISTNAME=	xtrs-4.9d
#PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.tim-mann.org/trs80/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	TRS-80 Model I/III/4 Emulator for Unix

BUILD_TARGET=	default

SUBST_CLASSES+=		mf
SUBST_STAGE.mf=		post-patch
SUBST_FILES.mf=		Makefile.local
SUBST_SED.mf=		-e 's|/usr/local|${PREFIX}|g' \
			-e 's|/usr/X11/|${X11PREFIX}/|g' \
			-e 's|/usr/include/X11|${X11BASE}/include|g' \
			-e 's|^\(LDFLAGS = \)-L/usr/X11R6/lib|\1-Wl,-R${X11BASE}/lib -L${X11BASE}/lib|g' \
			-e 's|/share/man|/man|g'

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALLATION_DIRS=	bin lib/xtrs ${PKGMANDIR}/man1 share/doc/xtrs share/xtrs

post-install:
	${INSTALL_DATA} ${WRKSRC}/xtrsrom4p.hex ${DESTDIR}${PREFIX}/lib/xtrs/romimage.m4p
	${INSTALL_DATA} ${WRKSRC}/xtrsrom4p.README ${DESTDIR}${PREFIX}/share/doc/xtrs
	${INSTALL_DATA} ${WRKSRC}/utility.dsk ${DESTDIR}${PREFIX}/share/xtrs
	${INSTALL_DATA} ${WRKSRC}/cpmutil.dsk ${DESTDIR}${PREFIX}/share/xtrs

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
