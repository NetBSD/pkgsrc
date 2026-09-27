# $NetBSD: Makefile,v 1.17 2026/09/27 11:36:46 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-gdk_pixbuf/}
PKGREVISION=	2
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - GDK Pixbuf plugin

GST_PLUGINS+=	gdk-pixbuf

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
