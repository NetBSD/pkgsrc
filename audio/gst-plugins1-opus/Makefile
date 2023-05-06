# $NetBSD: Makefile,v 1.5 2023/05/06 19:08:59 ryoon Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-opus/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Opus audio plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	opus

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
