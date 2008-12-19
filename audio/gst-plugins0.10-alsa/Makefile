# $NetBSD: Makefile,v 1.1.1.1 2008/12/19 04:40:39 jmcneill Exp $
#

GST_PLUGINS0.10_NAME=	alsa
GST_PLUGINS0.10_DIRS=	ext/alsa

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
