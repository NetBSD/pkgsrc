# $NetBSD: Makefile,v 1.1 2016/05/21 18:58:16 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-media-${MATE_VERSION}
CATEGORIES=	multimedia

COMMENT=	MATE media tools for MATE Desktop
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.1 AND gnu-lgpl-v2

EXTRACT_USING=	gtar

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-media

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../audio/libmatemixer/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-panel/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gst-mixer-applet
CONFIGURE_ARGS+=	--enable-gstmix
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
