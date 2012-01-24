# $NetBSD: Makefile,v 1.5 2012/01/24 09:10:55 sbd Exp $
#

GST_PLUGINS0.10_NAME=	pulse
GST_PLUGINS0.10_DIRS=	ext/pulse
GST_PLUGINS0.10_FLAGS=	pulse

PKGREVISION=	2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
