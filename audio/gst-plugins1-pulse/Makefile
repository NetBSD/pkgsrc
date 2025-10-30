# $NetBSD: Makefile,v 1.42 2025/10/30 15:35:41 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-pulse/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - PulseAudio plugin

GST_PLUGINS+=	pulse

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
