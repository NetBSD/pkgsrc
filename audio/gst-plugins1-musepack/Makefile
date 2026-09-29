# $NetBSD: Makefile,v 1.6 2026/09/29 06:03:48 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-musepack/}
PKGREVISION=	3
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Musepack plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	musepack

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/musepack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
