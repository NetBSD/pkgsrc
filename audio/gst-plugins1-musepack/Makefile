# $NetBSD: Makefile,v 1.1 2021/11/15 22:04:53 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-musepack/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Musepack plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	musepack

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/musepack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
