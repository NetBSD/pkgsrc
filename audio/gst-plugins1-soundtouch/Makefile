# $NetBSD: Makefile,v 1.9 2026/09/29 06:03:49 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-soundtouch/}
PKGREVISION=	3
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - SoundTouch plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	soundtouch

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
