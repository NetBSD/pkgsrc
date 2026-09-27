# $NetBSD: Makefile,v 1.11 2026/09/27 11:36:46 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-jpeg/}
PKGREVISION=	2
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - JPEG plugin

GST_PLUGINS+=	jpeg

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
