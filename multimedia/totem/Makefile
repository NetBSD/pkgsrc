# $NetBSD: Makefile,v 1.58 2012/09/07 19:17:17 adam Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=	11

DEPENDS+=	gst-plugins0.10-soup-[0-9]*:../../net/gst-plugins0.10-soup

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

CONFIGURE_ARGS+=	--disable-browser-plugins

BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.7

.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../net/libgdata/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
