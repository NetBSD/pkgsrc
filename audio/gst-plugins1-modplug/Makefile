# $NetBSD: Makefile,v 1.5 2026/09/27 11:34:55 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-modplug/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MOD/S3M/XM/IT decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	modplug

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
