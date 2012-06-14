# $NetBSD: Makefile,v 1.7 2012/06/14 07:44:21 sbd Exp $
#

GST_PLUGINS0.10_NAME=	resindvd
GST_PLUGINS0.10_FLAGS=	dvdnav
GST_PLUGINS0.10_DIRS=	ext/resindvd
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"
PKGREVISION=1

.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
