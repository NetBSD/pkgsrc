# $NetBSD: Makefile,v 1.13 2026/09/02 19:03:43 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-x265/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - HEVC/H.265 encoding plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gpl
GST_PLUGINS+=	x265

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
