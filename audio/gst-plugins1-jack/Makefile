# $NetBSD: Makefile,v 1.21 2026/09/02 19:00:51 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-jack/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - JACK plugin

GST_PLUGINS+=	jack

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
