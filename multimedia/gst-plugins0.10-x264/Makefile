# $NetBSD: Makefile,v 1.10 2012/03/03 00:14:27 wiz Exp $
#

GST_PLUGINS0.10_NAME=	x264
GST_PLUGINS0.10_DIRS=	ext/x264

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"
PKGREVISION=1

# need shared lib
BUILDLINK_API_DEPENDS.x264-devel+= x264-devel>=20071218nb1
.include "../../multimedia/x264-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
