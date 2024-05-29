# $NetBSD: Makefile,v 1.27 2024/05/29 16:33:53 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-rtmp/}
PKGREVISION=	2
CATEGORIES=	net gnome

COMMENT=	Open source multimedia framework - RTMP streaming plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	rtmp

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../net/rtmpdump/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
