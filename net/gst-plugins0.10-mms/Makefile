# $NetBSD: Makefile,v 1.9 2012/10/23 17:18:25 asau Exp $
#

GST_PLUGINS0.10_NAME=	mms
GST_PLUGINS0.10_FLAGS=	libmms
GST_PLUGINS0.10_DIRS=	ext/libmms
PKGREVISION=		2

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

BUILDLINK_API_DEPENDS.libmms+=	libmms>=0.4
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
