# $NetBSD: Makefile,v 1.53 2006/03/30 21:33:32 jmmv Exp $
#

DISTNAME=		gnome-utils-2.14.0
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-utils/2.14/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME2 utilities and applications

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake perl pkg-config
USE_DIRS+=		gnome2-1.5
USE_MSGFMT_PLURALS=	yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	gnome-dictionary/libgdict/gdict-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gnome-dictionary/libgdict/gdict-1.0-uninstalled.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

GCONF2_SCHEMAS+=	gnome-dictionary.schemas
GCONF2_SCHEMAS+=	gnome-screenshot.schemas
GCONF2_SCHEMAS+=	gnome-search-tool.schemas
GCONF2_SCHEMAS+=	logview.schemas

BUILDLINK_DEPENDS.glib2+=	glib2>=2.9.1
BUILDLINK_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.8.4
BUILDLINK_DEPENDS.libgnome+=	libgnome>=2.13.7
BUILDLINK_DEPENDS.libgnomeui+=	libgnomeui>=2.13.2

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
