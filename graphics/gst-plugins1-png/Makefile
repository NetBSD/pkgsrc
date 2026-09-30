# $NetBSD: Makefile,v 1.12 2026/09/30 18:51:23 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-png/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - PNG image plugin

GST_PLUGINS+=	png

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
