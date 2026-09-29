# $NetBSD: Makefile,v 1.29 2026/09/29 06:05:42 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-cairo/}
PKGREVISION=	3
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - Cairo plugin

GST_PLUGINS+=	cairo

.include "../../multimedia/gst-plugins1-good/Makefile.common"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
