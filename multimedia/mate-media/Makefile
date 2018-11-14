# $NetBSD: Makefile,v 1.16 2018/11/14 22:22:06 kleink Exp $

PKGREVISION= 3
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-media-${VERSION}
CATEGORIES=	multimedia

COMMENT=	MATE media tools for MATE Desktop
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.1 AND gnu-lgpl-v2

EXTRACT_USING=	gtar

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-media

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../audio/libmatemixer/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-panel/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gst-mixer-applet
CONFIGURE_ARGS+=	--enable-gstmix
.include "../../mk/bsd.pkg.mk"
