# $NetBSD: Makefile,v 1.9 2026/09/27 11:34:54 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-alsa/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - ALSA (Linux audio) plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	alsa

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
