# $NetBSD: Makefile,v 1.1.1.1 2003/09/26 10:29:52 martti Exp $

.include "Makefile.common"

DISTNAME=	xfce4-${XFCE4_VERSION}
DISTFILES=	# empty
CATEGORIES=	meta-pkgs
COMMENT=	XFce4

NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

# Basic stuff
.include "../../graphics/xfce4-iconbox/buildlink2.mk"
.include "../../print/xfce4-print/buildlink2.mk"
.include "../../sysutils/xfce4-fm/buildlink2.mk"
.include "../../wm/xfce4-wm/buildlink2.mk"
.include "../../x11/xfce4-desktop/buildlink2.mk"
.include "../../x11/xfce4-gtk2-engines/buildlink2.mk"
.include "../../x11/xfce4-utils/buildlink2.mk"
.include "../../x11/xfce4-panel/buildlink2.mk"

# Extras
.include "../../audio/xfce4-mixer/buildlink2.mk"
.include "../../graphics/xfce4-artwork/buildlink2.mk"
.include "../../sysutils/xfce4-fm-icons/buildlink2.mk"
.include "../../sysutils/xfce4-minicmd-plugin/buildlink2.mk"
.include "../../sysutils/xfce4-netload-plugin/buildlink2.mk"
.include "../../sysutils/xfce4-showdesktop-plugin/buildlink2.mk"
.include "../../sysutils/xfce4-systemload-plugin/buildlink2.mk"
.include "../../sysutils/xfce4-systray/buildlink2.mk"
.include "../../wm/xfce4-wm-themes/buildlink2.mk"
.include "../../x11/xfce4-themes/buildlink2.mk"
.include "../../x11/xfce4-toys/buildlink2.mk"
.include "../../x11/xfce4-trigger-launcher/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
