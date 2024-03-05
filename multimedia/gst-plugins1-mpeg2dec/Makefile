# $NetBSD: Makefile,v 1.6 2024/03/05 14:45:48 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-mpeg2dec/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - MPEG2 decoder plugin

GST_PLUGINS+=	gpl
GST_PLUGINS+=	mpeg2dec

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
