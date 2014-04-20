# $NetBSD: Makefile,v 1.5 2014/04/20 02:27:50 ryoon Exp $

GST_PLUGINS1_NAME=	pulse
GST_PLUGINS1_DIRS=	ext/pulse
GST_PLUGINS1_FLAGS=	pulse

.include "../../multimedia/gst-plugins1-good/Makefile.common"

PKGREVISION=		2

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
