# $NetBSD: Makefile,v 1.5 2022/04/18 12:36:05 nia Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-libvisual/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - audio visualization plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	libvisual

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libvisual/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
