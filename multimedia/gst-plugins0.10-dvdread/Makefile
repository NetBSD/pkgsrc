# $NetBSD: Makefile,v 1.5 2012/02/06 12:41:03 wiz Exp $
#

GST_PLUGINS0.10_NAME=	dvdread
GST_PLUGINS0.10_DIRS=	ext/dvdread

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

PKGREVISION=		1

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
