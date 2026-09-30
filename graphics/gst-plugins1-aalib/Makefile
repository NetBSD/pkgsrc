# $NetBSD: Makefile,v 1.9 2026/09/30 18:51:22 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-aalib/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - aalib plugin

GST_PLUGINS+=	aalib

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
