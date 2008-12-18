# $NetBSD: Makefile,v 1.1.1.1 2008/12/18 16:08:48 jmcneill Exp $
#

GST_PLUGINS0.10_NAME=	pulse
GST_PLUGINS0.10_DIRS=	ext/pulse
GST_PLUGINS0.10_FLAGS=	pulse

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
