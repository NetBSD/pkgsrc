# $NetBSD: Makefile,v 1.20 2026/09/30 18:51:18 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-vpx/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - VP8/VP9 plugin

GST_PLUGINS+=	vpx

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
