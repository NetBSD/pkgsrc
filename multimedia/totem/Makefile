# $NetBSD: Makefile,v 1.9 2006/03/21 06:00:47 jlam Exp $
#

.include "Makefile.common"

PKGREVISION=	5

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
