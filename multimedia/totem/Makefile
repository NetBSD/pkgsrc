# $NetBSD: Makefile,v 1.24 2008/01/18 05:08:38 tnn Exp $
#

.include "Makefile.common"

PKGREVISION=	1
COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

CONFIGURE_ARGS+=	--enable-gstreamer=yes

BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.7

.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
