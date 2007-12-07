# $NetBSD: Makefile,v 1.29 2007/12/07 19:43:21 martti Exp $

.include "Makefile.common"

DISTNAME=	xfce4-${XFCE4_VERSION}
DISTFILES=	# empty
#PKGREVISION=	1
CATEGORIES=	meta-pkgs
COMMENT=	Xfce

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty (meta-package)
WRKSRC=		${WRKDIR}

do-install:
	@${DO_NADA}

.include "../../audio/xfce4-mixer/buildlink3.mk"
.include "../../editors/xfce4-mousepad/buildlink3.mk"
.include "../../graphics/xfce4-icon-theme/buildlink3.mk"
.include "../../print/xfce4-print/buildlink3.mk"
.include "../../sysutils/xfce4-appfinder/buildlink3.mk"
.include "../../sysutils/xfce4-xarchiver/buildlink3.mk"
.include "../../time/xfce4-orage/buildlink3.mk"
.include "../../wm/xfce4-wm-themes/buildlink3.mk"
.include "../../wm/xfce4-wm/buildlink3.mk"
.include "../../x11/xfce4-desktop/buildlink3.mk"
.include "../../x11/xfce4-gtk2-engine/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-session/buildlink3.mk"
.include "../../x11/xfce4-terminal/buildlink3.mk"
.include "../../x11/xfce4-utils/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
