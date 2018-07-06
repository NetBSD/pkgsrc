# $NetBSD: Makefile,v 1.18 2018/07/06 15:06:43 ryoon Exp $

GST_PLUGINS1_NAME=	pulse
GST_PLUGINS1_DIRS=	ext/pulse
GST_PLUGINS1_FLAGS=	pulse

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-good/Makefile.common"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
