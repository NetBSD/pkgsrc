# $NetBSD: Makefile,v 1.4 2008/08/06 18:38:20 drochner Exp $
#

GST_PLUGINS0.10_NAME=	jack
GST_PLUGINS0.10_DIRS=	ext/jack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
