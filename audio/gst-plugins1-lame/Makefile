# $NetBSD: Makefile,v 1.12 2026/09/29 06:03:47 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-lame/}
PKGREVISION=	3
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MP3 encoder plugin

GST_PLUGINS+=	lame

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/lame/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
