# $NetBSD: Makefile,v 1.10 2020/03/08 16:50:52 wiz Exp $
#

GST_PLUGINS0.10_NAME=	mms
GST_PLUGINS0.10_FLAGS=	libmms
GST_PLUGINS0.10_DIRS=	ext/libmms
PKGREVISION=		3

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

BUILDLINK_API_DEPENDS.libmms+=	libmms>=0.4
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
