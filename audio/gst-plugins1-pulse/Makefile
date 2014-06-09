# $NetBSD: Makefile,v 1.6 2014/06/09 14:18:05 ryoon Exp $

GST_PLUGINS1_NAME=	pulse
GST_PLUGINS1_DIRS=	ext/pulse
GST_PLUGINS1_FLAGS=	pulse

.include "../../multimedia/gst-plugins1-good/Makefile.common"

PKGREVISION=		3

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
