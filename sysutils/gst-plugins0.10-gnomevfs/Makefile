# $NetBSD: Makefile,v 1.31 2012/06/14 07:44:23 sbd Exp $
#

GST_PLUGINS0.10_NAME=	gnomevfs
GST_PLUGINS0.10_DIRS=	ext/gnomevfs
GST_PLUGINS0.10_FLAGS=	gnome_vfs
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"
PKGREVISION=1

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
