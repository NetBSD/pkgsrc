# $NetBSD: Makefile,v 1.26 2005/06/01 18:02:51 jlam Exp $
#

.include		"../nethack-lib/Makefile.common"

PKGNAME=		nethack-x11-${NETHACK_VERSION}
COMMENT=		The X11 version of NetHack

CATEGORIES+=		x11

DEPENDS+=		nethack-lib-${NETHACK_VERSION}:../nethack-lib


BUILD_TARGET=		x11tiles nethack
INSTALL_TARGET=		binfiles
MAKE_ENV+=		GTYPE=-x11

ALLFILES+=		${DISTFILES}
FONTS_X11_DIRS+=	${PREFIX}/lib/X11/fonts/misc

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dat/x11tiles ${PREFIX}/share/${NETHACK_DIR}
	@${INSTALL_DATA} ${WRKSRC}/win/X11/NetHack.ad \
	    ${PREFIX}/lib/X11/app-defaults/NetHack
	@${INSTALL_DATA} ${WRKSRC}/win/X11/nh10.bdf ${PREFIX}/lib/X11/fonts/misc
	@${INSTALL_DATA} ${WRKSRC}/win/X11/nethack.rc \
	    ${PREFIX}/share/${NETHACK_DIR}/nethack.x11.rc

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
