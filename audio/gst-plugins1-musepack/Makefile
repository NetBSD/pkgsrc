# $NetBSD: Makefile,v 1.2 2025/10/23 20:35:46 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-musepack/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Musepack plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	musepack

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/musepack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
