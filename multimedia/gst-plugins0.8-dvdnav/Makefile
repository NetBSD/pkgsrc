# $NetBSD: Makefile,v 1.7 2008/06/20 01:09:28 joerg Exp $
#

GST_PLUGINS0.8_NAME=	dvdnav
GST_PLUGINS0.8_DIR=	ext/dvdnav

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		5

.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
