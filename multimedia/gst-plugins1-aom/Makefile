# $NetBSD: Makefile,v 1.7 2026/09/30 18:51:16 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-aom/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - AV1 plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	aom

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
