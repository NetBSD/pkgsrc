# $NetBSD: Makefile,v 1.8 2006/03/06 00:18:21 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	4

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
