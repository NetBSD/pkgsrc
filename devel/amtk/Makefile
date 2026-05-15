# $NetBSD: Makefile,v 1.23 2026/05/15 17:00:53 wiz Exp $

DISTNAME=	amtk-5.0.2
PKGREVISION=	18
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/amtk/5.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Amtk
COMMENT=	Actions, Menus and Toolbars Kit for GTK applications
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	msgfmt msgmerge xgettext

PKGCONFIG_OVERRIDE+=	amtk.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
