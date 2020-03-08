# $NetBSD: Makefile,v 1.3 2020/03/08 16:50:52 wiz Exp $

GST_PLUGINS1_NAME=	mms
GST_PLUGINS1_FLAGS=	libmms
GST_PLUGINS1_DIRS=	ext/libmms

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-bad/Makefile.common"

BUILDLINK_API_DEPENDS.libmms+=	libmms>=0.4
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
