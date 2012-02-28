# $NetBSD: Makefile,v 1.6 2012/02/28 18:43:42 drochner Exp $
#

GST_PLUGINS0.10_NAME=	dvdread
GST_PLUGINS0.10_DIRS=	ext/dvdread

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
