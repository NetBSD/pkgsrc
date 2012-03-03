# $NetBSD: Makefile,v 1.7 2012/03/03 00:14:26 wiz Exp $
#

GST_PLUGINS0.10_NAME=	vp8
GST_PLUGINS0.10_DIRS=	ext/vp8

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"
PKGREVISION=1

.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
