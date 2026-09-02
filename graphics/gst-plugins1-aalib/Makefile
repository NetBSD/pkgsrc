# $NetBSD: Makefile,v 1.6 2026/09/02 19:02:39 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-aalib/}
PKGREVISION=	1
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - aalib plugin

GST_PLUGINS+=	aalib

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
