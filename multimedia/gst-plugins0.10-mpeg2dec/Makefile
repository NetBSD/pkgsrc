# $NetBSD: Makefile,v 1.5 2011/04/22 13:45:22 obache Exp $
#

GST_PLUGINS0.10_NAME=	mpeg2dec
GST_PLUGINS0.10_DIRS=	ext/mpeg2dec

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-ugly/Makefile.common"

.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
