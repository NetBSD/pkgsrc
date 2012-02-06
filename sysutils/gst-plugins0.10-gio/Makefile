# $NetBSD: Makefile,v 1.4 2012/02/06 12:41:35 wiz Exp $
#

GST_PLUGINS0.10_NAME=	gio
GST_PLUGINS0.10_DIRS=	ext/gio
GST_PLUGINS0.10_FLAGS=	gio experimental

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

PKGREVISION=		1

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
