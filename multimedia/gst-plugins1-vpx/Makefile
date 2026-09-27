# $NetBSD: Makefile,v 1.18 2026/09/27 11:37:51 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-vpx/}
PKGREVISION=	2
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - VP8/VP9 plugin

GST_PLUGINS+=	vpx

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
