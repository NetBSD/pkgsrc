# $NetBSD: Makefile,v 1.30 2025/10/23 20:38:33 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-gtk/}
PKGREVISION=	2
CATEGORIES=	multimedia x11 gnome

COMMENT=	Open source multimedia framework - GTK plugin

GST_PLUGINS+=	gtk3

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
