# $NetBSD: Makefile,v 1.15 2005/01/17 12:56:13 martti Exp $

.include "Makefile.common"

DISTNAME=	xfce4-${XFCE4_VERSION}
DISTFILES=	# empty
CATEGORIES=	meta-pkgs
COMMENT=	XFce4

NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
NO_MTREE=	# defined

do-install:	# empty

.include "../../audio/xfce4-mixer/buildlink3.mk"
.include "../../graphics/xfce4-icon-theme/buildlink3.mk"
.include "../../graphics/xfce4-iconbox/buildlink3.mk"
.include "../../print/xfce4-print/buildlink3.mk"
.include "../../sysutils/xfce4-appfinder/buildlink3.mk"
.include "../../sysutils/xfce4-fm/buildlink3.mk"
.include "../../sysutils/xfce4-systray/buildlink3.mk"
.include "../../time/xfce4-calendar/buildlink3.mk"
.include "../../wm/xfce4-wm-themes/buildlink3.mk"
.include "../../wm/xfce4-wm/buildlink3.mk"
.include "../../x11/xfce4-desktop/buildlink3.mk"
.include "../../x11/xfce4-gtk2-engines/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-session/buildlink3.mk"
.include "../../x11/xfce4-toys/buildlink3.mk"
.include "../../x11/xfce4-trigger-launcher/buildlink3.mk"
.include "../../x11/xfce4-utils/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
