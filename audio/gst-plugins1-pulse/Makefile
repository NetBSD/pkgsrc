# $NetBSD: Makefile,v 1.27 2021/11/15 22:01:17 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-pulse/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - PulseAudio plugin

GST_PLUGINS+=	pulse

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
