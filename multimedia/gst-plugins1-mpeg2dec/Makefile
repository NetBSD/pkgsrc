# $NetBSD: Makefile,v 1.7 2025/10/23 20:38:34 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-mpeg2dec/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - MPEG2 decoder plugin

GST_PLUGINS+=	gpl
GST_PLUGINS+=	mpeg2dec

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
