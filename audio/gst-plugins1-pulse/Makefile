# $NetBSD: Makefile,v 1.25 2021/02/07 06:30:13 ryoon Exp $

GST_PLUGINS1_NAME=	pulse
GST_PLUGINS1_DIRS=	ext/pulse
GST_PLUGINS1_FLAGS=	pulse

PKGREVISION= 5
.include "../../multimedia/gst-plugins1-good/Makefile.common"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
