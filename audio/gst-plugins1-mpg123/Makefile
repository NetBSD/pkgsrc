# $NetBSD: Makefile,v 1.4 2021/11/15 22:01:16 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-mpg123/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MP3 decoder plugin

GST_PLUGINS+=	mpg123

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
