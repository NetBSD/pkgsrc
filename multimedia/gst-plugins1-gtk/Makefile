# $NetBSD: Makefile,v 1.25 2024/12/27 08:20:23 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-gtk/}
PKGREVISION=	1
CATEGORIES=	multimedia x11 gnome

COMMENT=	Open source multimedia framework - GTK plugin

GST_PLUGINS+=	gtk3

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
