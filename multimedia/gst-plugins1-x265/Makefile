# $NetBSD: Makefile,v 1.16 2026/09/30 18:51:19 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-x265/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - HEVC/H.265 encoding plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gpl
GST_PLUGINS+=	x265

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
