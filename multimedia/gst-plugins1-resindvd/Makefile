# $NetBSD: Makefile,v 1.13 2026/09/27 11:37:50 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-resindvd/}
PKGREVISION=	2
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - DVD navigation plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gpl
GST_PLUGINS+=	resindvd

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
