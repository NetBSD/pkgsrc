# $NetBSD: Makefile,v 1.7 2026/09/27 11:36:46 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-aalib/}
PKGREVISION=	2
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - aalib plugin

GST_PLUGINS+=	aalib

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
