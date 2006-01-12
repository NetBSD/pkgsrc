# $NetBSD: Makefile,v 1.4 2006/01/12 16:57:49 jmmv Exp $
#

.include "Makefile.common"

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

BUILDLINK_DEPENDS.gstreamer+=	gstreamer>=0.8.6.1

.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
