# $NetBSD: Makefile,v 1.7 2026/09/02 19:00:52 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-soundtouch/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - SoundTouch plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	soundtouch

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
