# $NetBSD: Makefile,v 1.4 2021/12/08 16:03:13 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-libvisual/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - audio visualization plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	libvisual

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libvisual/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
