# $NetBSD: Makefile,v 1.6 2012/03/03 00:14:27 wiz Exp $
#

GST_PLUGINS0.10_NAME=	mms
GST_PLUGINS0.10_FLAGS=	libmms
GST_PLUGINS0.10_DIRS=	ext/libmms

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"
PKGREVISION=1

BUILDLINK_API_DEPENDS.libmms+=	libmms>=0.4
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
