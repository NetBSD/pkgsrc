# $NetBSD: Makefile,v 1.39 2025/10/23 20:36:20 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-pango/}
PKGREVISION=	1
CATEGORIES=	devel gnome

COMMENT=	Open source multimedia framework - pango plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	pango

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
