# $NetBSD: Makefile,v 1.28 2022/04/18 12:36:06 nia Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-pango/}
CATEGORIES=	devel gnome

COMMENT=	Open source multimedia framework - pango plugin

GST_EXT_BUILD=          # defined

GST_PLUGINS+=		pango

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
