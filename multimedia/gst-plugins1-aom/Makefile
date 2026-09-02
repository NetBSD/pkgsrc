# $NetBSD: Makefile,v 1.4 2026/09/02 19:03:41 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-aom/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - AV1 plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	aom

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
