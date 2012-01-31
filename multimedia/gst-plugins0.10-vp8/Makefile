# $NetBSD: Makefile,v 1.4 2012/01/31 12:00:25 ryoon Exp $
#

PKGREVISION=	1

GST_PLUGINS0.10_NAME=	vp8
GST_PLUGINS0.10_DIRS=	ext/vp8

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
