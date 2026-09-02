# $NetBSD: Makefile,v 1.36 2026/09/02 19:00:51 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-lv2/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - LV2 support plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	lv2

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/lilv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
