# $NetBSD: Makefile,v 1.10 2026/09/27 11:34:56 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-opus/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Opus audio plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	opus

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
