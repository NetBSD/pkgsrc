# $NetBSD: Makefile,v 1.6 2025/10/23 20:38:34 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-ogg/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - Ogg plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	ogg

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
