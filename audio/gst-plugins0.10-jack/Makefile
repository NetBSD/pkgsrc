# $NetBSD: Makefile,v 1.7 2011/05/18 09:49:00 drochner Exp $
#

GST_PLUGINS0.10_NAME=	jack
GST_PLUGINS0.10_DIRS=	ext/jack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
