# $NetBSD: Makefile,v 1.2 2008/07/14 12:55:56 joerg Exp $
#

GST_PLUGINS0.10_NAME=	jack
GST_PLUGINS0.10_DIRS=	ext/jack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

.include "../../audio/jack-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
