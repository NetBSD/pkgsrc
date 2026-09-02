# $NetBSD: Makefile,v 1.8 2026/09/02 19:00:50 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-dts/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - DTS plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gpl
GST_PLUGINS+=	dts

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/libdca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
