# $NetBSD: Makefile,v 1.34 2012/10/08 23:02:26 adam Exp $
#

GST_PLUGINS0.10_NAME=	gnomevfs
GST_PLUGINS0.10_DIRS=	ext/gnomevfs
GST_PLUGINS0.10_FLAGS=	gnome_vfs
PKGREVISION=		4

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
