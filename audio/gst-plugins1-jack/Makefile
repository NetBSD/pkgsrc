# $NetBSD: Makefile,v 1.22 2026/09/27 11:34:55 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-jack/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - JACK plugin

GST_PLUGINS+=	jack

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
