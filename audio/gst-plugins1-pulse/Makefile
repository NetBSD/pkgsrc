# $NetBSD: Makefile,v 1.37 2024/01/30 14:21:31 ryoon Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-pulse/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - PulseAudio plugin

GST_PLUGINS+=	pulse

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
