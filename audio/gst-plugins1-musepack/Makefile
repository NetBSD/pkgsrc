# $NetBSD: Makefile,v 1.5 2026/09/27 11:34:56 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-musepack/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Musepack plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	musepack

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/musepack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
