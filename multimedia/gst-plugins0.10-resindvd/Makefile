# $NetBSD: Makefile,v 1.1.1.1 2009/03/09 16:04:36 drochner Exp $
#

GST_PLUGINS0.10_NAME=	resindvd
GST_PLUGINS0.10_FLAGS=	dvdnav
GST_PLUGINS0.10_DIRS=	ext/resindvd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
