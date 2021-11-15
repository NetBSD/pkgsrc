# $NetBSD: Makefile,v 1.7 2021/11/15 22:01:20 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-resindvd/}
CATEGORIES=	net gnome

COMMENT=	Open source multimedia framework - DVD navigation plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	resindvd

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
