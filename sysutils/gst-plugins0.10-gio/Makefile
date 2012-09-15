# $NetBSD: Makefile,v 1.8 2012/09/15 10:06:26 obache Exp $
#

GST_PLUGINS0.10_NAME=	gio
GST_PLUGINS0.10_DIRS=	ext/gio
GST_PLUGINS0.10_FLAGS=	gio experimental
PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
