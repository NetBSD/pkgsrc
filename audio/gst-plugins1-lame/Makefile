# $NetBSD: Makefile,v 1.9 2026/07/17 13:42:17 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-lame/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MP3 encoder plugin

GST_PLUGINS+=	lame

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/lame/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
