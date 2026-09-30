# $NetBSD: Makefile,v 1.11 2026/09/30 18:51:22 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-vorbis/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Vorbis audio plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	vorbis

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
