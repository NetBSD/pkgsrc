# $NetBSD: Makefile,v 1.11 2026/09/27 11:34:55 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-lame/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MP3 encoder plugin

GST_PLUGINS+=	lame

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/lame/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
