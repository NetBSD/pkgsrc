# $NetBSD: Makefile,v 1.10 2026/09/30 18:51:22 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-soundtouch/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - SoundTouch plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	soundtouch

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
