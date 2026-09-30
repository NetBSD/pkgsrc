# $NetBSD: Makefile,v 1.7 2026/09/30 18:51:23 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-webp/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - WebP image plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	webp

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
