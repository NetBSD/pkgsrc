# $NetBSD: Makefile,v 1.15 2025/02/12 06:44:22 ryoon Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-jack/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - JACK plugin

GST_PLUGINS+=	jack

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/jack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
