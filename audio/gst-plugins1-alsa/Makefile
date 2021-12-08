# $NetBSD: Makefile,v 1.4 2021/12/08 16:03:12 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-alsa/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - ALSA (Linux audio) plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	alsa

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
