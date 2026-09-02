# $NetBSD: Makefile,v 1.10 2026/09/02 19:02:40 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-jpeg/}
PKGREVISION=	1
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - JPEG plugin

GST_PLUGINS+=	jpeg

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
