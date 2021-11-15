# $NetBSD: Makefile,v 1.4 2021/11/15 22:01:17 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-sid/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Commodore 64 audio plugin

GST_PLUGINS+=	sidplay

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
