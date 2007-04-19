# $NetBSD: Makefile,v 1.66 2007/04/19 21:39:59 wiz Exp $
#

DISTNAME=		gnome-utils-2.18.1
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-utils/2.18/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME2 utilities and applications

USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	gnome-dictionary/libgdict/gdict-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome-dictionary/libgdict/gdict-1.0-uninstalled.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no

GCONF2_SCHEMAS+=	baobab.schemas
GCONF2_SCHEMAS+=	gnome-dictionary.schemas
GCONF2_SCHEMAS+=	gnome-screenshot.schemas
GCONF2_SCHEMAS+=	gnome-search-tool.schemas
GCONF2_SCHEMAS+=	logview.schemas

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.9.1
BUILDLINK_API_DEPENDS.gnome-panel+=	gnome-panel>=2.13.4
BUILDLINK_API_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.8.4
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.13.2
BUILDLINK_API_DEPENDS.libgnomecanvas+=	libgnomecanvas>=2.10.2
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.13.7

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/libgtop2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
