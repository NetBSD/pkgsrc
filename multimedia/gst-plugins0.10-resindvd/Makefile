# $NetBSD: Makefile,v 1.2 2011/04/22 13:45:20 obache Exp $
#

GST_PLUGINS0.10_NAME=	resindvd
GST_PLUGINS0.10_FLAGS=	dvdnav
GST_PLUGINS0.10_DIRS=	ext/resindvd

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
