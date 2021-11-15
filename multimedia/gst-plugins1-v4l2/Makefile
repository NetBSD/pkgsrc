# $NetBSD: Makefile,v 1.6 2021/11/15 22:01:21 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-v4l2/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - Webcam plugin

GST_PLUGINS+=	v4l2
GST_PLUGINS+=	v4l2-libv4l2

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
