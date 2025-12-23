# $NetBSD: Makefile,v 1.15 2025/12/23 11:01:32 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-x264/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - H.264/MPEG-4 encoder plugin

GST_PLUGINS+=	gpl
GST_PLUGINS+=	x264

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../multimedia/x264/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
