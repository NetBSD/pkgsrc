# $NetBSD: Makefile,v 1.9 2026/09/02 19:02:40 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-png/}
PKGREVISION=	1
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - PNG image plugin

GST_PLUGINS+=	png

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
