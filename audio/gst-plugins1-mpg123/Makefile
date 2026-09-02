# $NetBSD: Makefile,v 1.7 2026/09/02 19:00:51 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-mpg123/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MP3 decoder plugin

GST_PLUGINS+=	mpg123

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
