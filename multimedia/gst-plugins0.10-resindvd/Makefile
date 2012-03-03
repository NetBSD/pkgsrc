# $NetBSD: Makefile,v 1.6 2012/03/03 00:14:26 wiz Exp $
#

GST_PLUGINS0.10_NAME=	resindvd
GST_PLUGINS0.10_FLAGS=	dvdnav
GST_PLUGINS0.10_DIRS=	ext/resindvd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"
PKGREVISION=1

.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
