# $NetBSD: Makefile,v 1.3 2011/05/18 09:48:59 drochner Exp $
#

GST_PLUGINS0.10_NAME=	alsa
GST_PLUGINS0.10_DIRS=	ext/alsa

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
