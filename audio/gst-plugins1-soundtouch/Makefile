# $NetBSD: Makefile,v 1.4 2021/11/15 22:01:17 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-soundtouch/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - SoundTouch plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	soundtouch

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
