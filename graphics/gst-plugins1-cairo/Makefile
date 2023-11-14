# $NetBSD: Makefile,v 1.19 2023/11/14 14:02:05 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-cairo/}
PKGREVISION=	2
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - Cairo plugin

GST_PLUGINS+=	cairo

.include "../../multimedia/gst-plugins1-good/Makefile.common"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
