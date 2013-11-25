# $NetBSD: Makefile,v 1.2 2013/11/25 12:00:46 wiz Exp $
#

GST_PLUGINS1_NAME=	pulse
GST_PLUGINS1_DIRS=	ext/pulse
GST_PLUGINS1_FLAGS=	pulse

.include "../../multimedia/gst-plugins1-good/Makefile.common"

PKGREVISION=		1

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
