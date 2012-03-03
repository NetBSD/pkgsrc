# $NetBSD: Makefile,v 1.9 2012/03/03 00:14:26 wiz Exp $
#

GST_PLUGINS0.10_NAME=	mpeg2dec
GST_PLUGINS0.10_DIRS=	ext/mpeg2dec

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"
PKGREVISION=1

.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
