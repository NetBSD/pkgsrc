# $NetBSD: Makefile,v 1.3 2008/07/31 04:02:40 bjs Exp $
#

GST_PLUGINS0.10_NAME=	jack
PKGREVISION=		1
GST_PLUGINS0.10_DIRS=	ext/jack

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-bad/Makefile.common"

.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
