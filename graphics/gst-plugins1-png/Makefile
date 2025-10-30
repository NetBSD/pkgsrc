# $NetBSD: Makefile,v 1.8 2025/10/30 15:35:42 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-png/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - PNG image plugin

GST_PLUGINS+=	png

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
