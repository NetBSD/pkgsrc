# $NetBSD: Makefile,v 1.7 2026/09/27 11:34:55 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-gme/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Game Music Emu plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gme

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/game-music-emu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
