# $NetBSD: Makefile,v 1.4 2021/11/15 22:01:15 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-dts/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - DTS plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	dts

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/libdca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
