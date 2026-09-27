# $NetBSD: Makefile,v 1.17 2026/09/27 11:37:51 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-x264/}
PKGREVISION=	2
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - H.264/MPEG-4 encoder plugin

GST_PLUGINS+=	gpl
GST_PLUGINS+=	x264

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../multimedia/x264/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
