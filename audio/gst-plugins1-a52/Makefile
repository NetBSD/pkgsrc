# $NetBSD: Makefile,v 1.6 2022/12/16 21:08:09 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-a52/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Dolby AC-3 audio plugin

GST_PLUGINS+=	a52dec

MESON_ARGS+=	-Dgpl=enabled

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
