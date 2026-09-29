# $NetBSD: Makefile,v 1.6 2026/09/29 06:03:47 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-modplug/}
PKGREVISION=	3
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MOD/S3M/XM/IT decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	modplug

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
