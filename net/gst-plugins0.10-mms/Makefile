# $NetBSD: Makefile,v 1.8 2012/09/15 10:06:00 obache Exp $
#

GST_PLUGINS0.10_NAME=	mms
GST_PLUGINS0.10_FLAGS=	libmms
GST_PLUGINS0.10_DIRS=	ext/libmms
PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

BUILDLINK_API_DEPENDS.libmms+=	libmms>=0.4
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
