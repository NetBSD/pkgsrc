# $NetBSD: Makefile,v 1.7 2025/10/23 20:35:47 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-sid/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Commodore 64 audio plugin

GST_PLUGINS+=	gpl
GST_PLUGINS+=	sidplay

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
