# $NetBSD: Makefile,v 1.14 2022/04/18 12:36:06 nia Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-cairo/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - Cairo plugin

GST_PLUGINS+=	cairo

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
