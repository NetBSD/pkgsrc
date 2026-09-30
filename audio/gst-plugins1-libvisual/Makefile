# $NetBSD: Makefile,v 1.11 2026/09/30 18:51:20 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-libvisual/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - audio visualization plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	libvisual

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libvisual/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
