# $NetBSD: Makefile,v 1.6 2022/07/18 15:40:56 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-fluidsynth/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MIDI plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	fluidsynth

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
