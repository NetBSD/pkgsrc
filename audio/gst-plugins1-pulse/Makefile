# $NetBSD: Makefile,v 1.26 2021/07/30 12:26:38 ryoon Exp $

GST_PLUGINS1_NAME=	pulse
GST_PLUGINS1_DIRS=	ext/pulse
GST_PLUGINS1_FLAGS=	pulse

PKGREVISION= 6
.include "../../multimedia/gst-plugins1-good/Makefile.common"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
