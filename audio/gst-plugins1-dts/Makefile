# $NetBSD: Makefile,v 1.5 2022/04/18 12:36:04 nia Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-dts/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - DTS plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gpl
GST_PLUGINS+=	dts

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/libdca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
