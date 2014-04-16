# $NetBSD: Makefile,v 1.4 2014/04/16 11:22:01 wiz Exp $

GST_PLUGINS1_NAME=	pulse
GST_PLUGINS1_DIRS=	ext/pulse
GST_PLUGINS1_FLAGS=	pulse

.include "../../multimedia/gst-plugins1-good/Makefile.common"

PKGREVISION=		1

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
