# $NetBSD: Makefile,v 1.30 2023/01/29 21:15:46 ryoon Exp $

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
