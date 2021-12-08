# $NetBSD: Makefile,v 1.2 2021/12/08 16:03:13 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-fluidsynth/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MIDI plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	fluidsynth

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
