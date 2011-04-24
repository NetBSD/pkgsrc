# $NetBSD: Makefile,v 1.3 2011/04/24 15:31:09 obache Exp $
#

GST_PLUGINS0.10_NAME=	vorbis
GST_PLUGINS0.10_DIRS=	ext/vorbis
GST_PLUGINS0.10_FLAGS=	vorbis

PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
