# $NetBSD: Makefile,v 1.8 2012/06/14 07:44:17 sbd Exp $
#

GST_PLUGINS0.10_NAME=	dvdread
GST_PLUGINS0.10_DIRS=	ext/dvdread
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"
PKGREVISION=1

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
