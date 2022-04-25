# $NetBSD: Makefile,v 1.6 2022/04/25 06:44:20 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-dvdread/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - DVD plugin

GST_PLUGINS+=	dvdread

MESON_ARGS+=	-Dgpl=enabled

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
