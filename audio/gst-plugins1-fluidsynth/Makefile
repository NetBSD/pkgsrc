# $NetBSD: Makefile,v 1.23 2026/09/27 11:34:55 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-fluidsynth/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MIDI plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	fluidsynth

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
