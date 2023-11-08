# $NetBSD: Makefile,v 1.24 2023/11/08 13:20:26 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-rtmp/}
PKGREVISION=	2
CATEGORIES=	net gnome

COMMENT=	Open source multimedia framework - RTMP streaming plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	rtmp

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../net/rtmpdump/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
