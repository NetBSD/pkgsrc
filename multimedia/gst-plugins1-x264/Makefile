# $NetBSD: Makefile,v 1.9 2022/09/30 07:01:13 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-x264/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - H.264/MPEG-4 encoder plugin

GST_PLUGINS+=	x264

MESON_ARGS+=	-Dgpl=enabled

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../multimedia/x264/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
