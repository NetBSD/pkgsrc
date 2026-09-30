# $NetBSD: Makefile,v 1.12 2026/09/30 18:51:18 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-v4l2/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - Webcam plugin

GST_PLUGINS+=	v4l2
GST_PLUGINS+=	v4l2-libv4l2

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
