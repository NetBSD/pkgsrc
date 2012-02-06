# $NetBSD: Makefile,v 1.28 2012/02/06 12:41:35 wiz Exp $
#

GST_PLUGINS0.10_NAME=	gnomevfs
GST_PLUGINS0.10_DIRS=	ext/gnomevfs
GST_PLUGINS0.10_FLAGS=	gnome_vfs

PKGREVISION=		4

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
