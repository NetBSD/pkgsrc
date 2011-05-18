# $NetBSD: Makefile,v 1.3 2011/05/18 09:49:03 drochner Exp $
#

GST_PLUGINS0.10_NAME=	gio
GST_PLUGINS0.10_DIRS=	ext/gio
GST_PLUGINS0.10_FLAGS=	gio experimental

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
