# $NetBSD: Makefile,v 1.10 2012/09/22 13:48:18 ryoon Exp $
#

GST_PLUGINS0.10_NAME=	vp8
GST_PLUGINS0.10_DIRS=	ext/vp8
PKGREVISION=		3

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
