# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:18 joerg Exp $
#

.include "Makefile.common"

PKGREVISION=	3

COMMENT+=	(using GStreamer)

CONFLICTS+=	totem-xine-[0-9]*

.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
