# $NetBSD: Makefile,v 1.3 2021/11/15 22:01:16 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-gme/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Game Music Emu plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gme

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/game-music-emu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
