# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:41 tv Exp $
#

DISTNAME=	xtrs-4.9
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.tim-mann.org/trs80/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	TRS-80 Model I/III/4 Emulator for Unix

USE_BUILDLINK3=	yes
USE_X11=	yes

ALL_TARGET=	default

SUBST_CLASSES+=		mf
SUBST_STAGE.mf=		post-patch
SUBST_FILES.mf=		Makefile.local
SUBST_SED.mf=		-e 's|/usr/local|${PREFIX}|g' \
			-e 's|/usr/X11/|${X11PREFIX}/|g' \
			-e 's|/usr/include/X11|${X11BASE}/include|g' \
			-e 's|^\(LDFLAGS = \)-L\(/usr/X11R6/lib\)|\1-Wl,-R\2 -L\2|g' \
			-e 's|/share/man|/man|g'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xtrs
	${INSTALL_DATA} ${WRKSRC}/xtrsrom4p.hex ${PREFIX}/lib/xtrs/romimage.m4p
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xtrs
	${INSTALL_DATA} ${WRKSRC}/xtrsrom4p.README ${PREFIX}/share/doc/xtrs

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
