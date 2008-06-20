# $NetBSD: Makefile,v 1.2 2008/06/20 01:09:06 joerg Exp $
#

GST_PLUGINS0.10_NAME=	vorbis
GST_PLUGINS0.10_DIRS=	ext/vorbis
GST_PLUGINS0.10_FLAGS=	vorbis

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
