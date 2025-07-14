# $NetBSD: Makefile,v 1.16 2025/07/14 16:05:48 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-jack/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - JACK plugin

GST_PLUGINS+=	jack

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
