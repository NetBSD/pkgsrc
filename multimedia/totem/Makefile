# $NetBSD: Makefile,v 1.5 2006/01/18 12:55:55 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=	1

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
