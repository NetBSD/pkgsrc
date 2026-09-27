# $NetBSD: Makefile,v 1.46 2026/09/27 11:34:56 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-pulse/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - PulseAudio plugin

GST_PLUGINS+=	pulse

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
