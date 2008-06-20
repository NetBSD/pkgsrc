# $NetBSD: Makefile,v 1.12 2008/06/20 01:09:36 joerg Exp $
#

GST_PLUGINS0.8_NAME=	gnomevfs
GST_PLUGINS0.8_DIR=	ext/gnomevfs
GST_PLUGINS0.8_FLAG=	gnome_vfs

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		10

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
