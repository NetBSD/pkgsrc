# $NetBSD: Makefile,v 1.14 2025/10/23 20:37:32 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-gdk_pixbuf/}
PKGREVISION=	2
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - GDK Pixbuf plugin

GST_PLUGINS+=	gdk-pixbuf

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
