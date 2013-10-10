# $NetBSD: Makefile,v 1.71 2013/10/10 14:41:52 ryoon Exp $
#

.include "Makefile.common"

PKGREVISION=	23

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
