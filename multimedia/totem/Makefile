# $NetBSD: Makefile,v 1.32 2009/02/21 17:40:00 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

CONFIGURE_ARGS+=	--enable-gstreamer=yes
CONFIGURE_ARGS+=	--disable-browser-plugins

BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.7

.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
