# $NetBSD: Makefile,v 1.24 2026/09/30 18:51:20 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-jack/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - JACK plugin

GST_PLUGINS+=	jack

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
