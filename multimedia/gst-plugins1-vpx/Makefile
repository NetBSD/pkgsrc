# $NetBSD: Makefile,v 1.15 2025/10/23 20:38:35 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-vpx/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - VP8/VP9 plugin

GST_PLUGINS+=	vpx

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
