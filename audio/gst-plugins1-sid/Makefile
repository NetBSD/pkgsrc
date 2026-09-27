# $NetBSD: Makefile,v 1.10 2026/09/27 11:34:56 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-sid/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Commodore 64 audio plugin

GST_PLUGINS+=	gpl
GST_PLUGINS+=	sidplay

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../audio/libsidplay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
