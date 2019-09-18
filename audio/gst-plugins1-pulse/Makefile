# $NetBSD: Makefile,v 1.20 2019/09/18 14:17:04 ryoon Exp $

GST_PLUGINS1_NAME=	pulse
GST_PLUGINS1_DIRS=	ext/pulse
GST_PLUGINS1_FLAGS=	pulse

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-good/Makefile.common"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
