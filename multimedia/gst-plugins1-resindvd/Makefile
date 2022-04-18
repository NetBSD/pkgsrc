# $NetBSD: Makefile,v 1.8 2022/04/18 12:36:09 nia Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-resindvd/}
CATEGORIES=	net gnome

COMMENT=	Open source multimedia framework - DVD navigation plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gpl
GST_PLUGINS+=	resindvd

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
