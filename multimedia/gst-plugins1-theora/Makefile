# $NetBSD: Makefile,v 1.10 2026/09/02 19:03:43 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-theora/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - Theora video plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	theora

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
