# $NetBSD: Makefile,v 1.4 2022/04/18 12:36:05 nia Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-opus/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Opus audio plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	opus

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
