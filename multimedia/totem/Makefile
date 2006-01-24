# $NetBSD: Makefile,v 1.6 2006/01/24 07:32:28 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	2

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
