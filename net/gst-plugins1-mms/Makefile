# $NetBSD: Makefile,v 1.2 2014/08/08 21:31:08 wiz Exp $

GST_PLUGINS1_NAME=	mms
GST_PLUGINS1_FLAGS=	libmms
GST_PLUGINS1_DIRS=	ext/libmms

.include "../../multimedia/gst-plugins1-bad/Makefile.common"

BUILDLINK_API_DEPENDS.libmms+=	libmms>=0.4
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
