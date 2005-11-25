# $NetBSD: Makefile,v 1.2 2005/11/25 21:23:16 wiz Exp $
#

.include "Makefile.common"

COMMENT+=	(using GStreamer)
PKGREVISION=	1

CONFLICTS+=	totem-xine-[0-9]*

BUILDLINK_DEPENDS.gstreamer+=	gstreamer>=0.8.6.1

.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
