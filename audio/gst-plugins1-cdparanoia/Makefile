# $NetBSD: Makefile,v 1.9 2026/09/27 11:34:54 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-cdparanoia/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - CD audio plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	cdparanoia

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
