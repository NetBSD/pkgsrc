# $NetBSD: Makefile,v 1.4 2023/11/08 13:20:26 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-adaptivedemux2/}
PKGREVISION=	1
CATEGORIES=	net gnome

COMMENT=	Open source multimedia framework - adaptive format (HLS/DASH) plugin

GST_PLUGINS+=	adaptivedemux2

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
