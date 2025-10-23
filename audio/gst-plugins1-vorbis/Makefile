# $NetBSD: Makefile,v 1.6 2025/10/23 20:35:47 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-vorbis/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Vorbis audio plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	vorbis

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
