# $NetBSD: Makefile,v 1.9 2006/02/05 23:09:05 joerg Exp $
#

DISTNAME=	xtrs-4.9
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.tim-mann.org/trs80/

MAINTAINER=	tech-pkg@NetBSD.org
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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xtrs
	${INSTALL_DATA} ${WRKSRC}/xtrsrom4p.hex ${PREFIX}/lib/xtrs/romimage.m4p
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xtrs
	${INSTALL_DATA} ${WRKSRC}/xtrsrom4p.README ${PREFIX}/share/doc/xtrs

# The sources assume <malloc.h> exists.  Create a fake one for platforms
# that don't have it.
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then		\
		${ECHO} "#include <stdlib.h>"			\
			> ${BUILDLINK_DIR}/include/malloc.h;	\
	fi

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
