# $NetBSD: Makefile,v 1.21 2007/09/19 23:19:04 wiz Exp $
#

.include "Makefile.common"

COMMENT+=	(using GStreamer)
PKGREVISION=	1

CONFLICTS+=	totem-xine-[0-9]*

CONFIGURE_ARGS+=	--enable-gstreamer=yes

BUILDLINK_API_DEPENDS.gst-plugins0.10-base+=	gst-plugins0.10-base>=0.10.7

.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
