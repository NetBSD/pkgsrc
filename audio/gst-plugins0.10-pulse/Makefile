# $NetBSD: Makefile,v 1.2 2011/04/22 13:42:54 obache Exp $
#

GST_PLUGINS0.10_NAME=	pulse
GST_PLUGINS0.10_DIRS=	ext/pulse
GST_PLUGINS0.10_FLAGS=	pulse

PKGREVISION=	1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
