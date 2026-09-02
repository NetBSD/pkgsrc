# $NetBSD: Makefile,v 1.4 2026/09/02 19:02:40 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-webp/}
PKGREVISION=	1
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - WebP image plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	webp

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
