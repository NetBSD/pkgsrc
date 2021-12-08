# $NetBSD: Makefile,v 1.4 2021/12/08 16:05:48 adam Exp $

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
