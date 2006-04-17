# $NetBSD: Makefile,v 1.12 2006/04/17 14:52:11 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	2

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

CONFIGURE_ARGS+=	--enable-gstreamer=0.10

.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
