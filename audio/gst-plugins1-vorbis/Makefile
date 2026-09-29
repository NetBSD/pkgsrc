# $NetBSD: Makefile,v 1.10 2026/09/29 06:03:49 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-vorbis/}
PKGREVISION=	3
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Vorbis audio plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	vorbis

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
