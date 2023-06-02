# $NetBSD: Makefile,v 1.6 2023/06/02 16:09:45 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-opus/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Opus audio plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	opus

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
