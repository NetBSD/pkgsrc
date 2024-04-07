# $NetBSD: Makefile,v 1.19 2024/04/07 07:34:43 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-gtk/}
PKGREVISION=	2
CATEGORIES=	multimedia x11 gnome

COMMENT=	Open source multimedia framework - GTK plugin

GST_PLUGINS+=	gtk3

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
