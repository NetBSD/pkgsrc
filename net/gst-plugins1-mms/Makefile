# $NetBSD: Makefile,v 1.4 2021/11/15 22:01:22 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-mms/}
CATEGORIES=	net gnome

COMMENT=	Open source multimedia framework - MMS plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	libmms

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
