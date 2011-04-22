# $NetBSD: Makefile,v 1.6 2011/04/22 13:45:22 obache Exp $
#

GST_PLUGINS0.10_NAME=	x264
GST_PLUGINS0.10_DIRS=	ext/x264

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

# need shared lib
BUILDLINK_API_DEPENDS.x264-devel+= x264-devel>=20071218nb1
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
