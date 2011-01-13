# $NetBSD: Makefile,v 1.21 2011/01/13 13:39:23 wiz Exp $
#

GST_PLUGINS0.10_NAME=	gnomevfs
GST_PLUGINS0.10_DIRS=	ext/gnomevfs
GST_PLUGINS0.10_FLAGS=	gnome_vfs

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"
PKGREVISION=		1

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
