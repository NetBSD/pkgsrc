# $NetBSD: Makefile,v 1.3 2021/11/15 22:01:20 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-ogg/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - Ogg plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	ogg

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
