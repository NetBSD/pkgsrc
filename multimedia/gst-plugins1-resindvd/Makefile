# $NetBSD: Makefile,v 1.9 2022/12/16 21:08:09 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-resindvd/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - DVD navigation plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gpl
GST_PLUGINS+=	resindvd

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
