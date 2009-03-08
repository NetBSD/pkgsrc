# $NetBSD: Makefile,v 1.4 2009/03/08 15:56:45 wiz Exp $
#

DISTNAME=		tomboy-0.12.2
CATEGORIES=		editors misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/tomboy/0.12/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/tomboy
COMMENT=		Gnome desktop note application

GNU_CONFIGURE=  yes
USE_DIRS=	xdg-1.4 gnome2-1.6
USE_LIBTOOL=    yes
USE_TOOLS+=     gmake intltool pkg-config bash:run

CONFIGURE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
GCONF_SCHEMAS=	tomboy.schemas

PKGCONFIG_OVERRIDE+=	data/tomboy-addins.pc.in

.include "../../devel/GConf/schemas.mk"
.include "../../devel/atk/buildlink3.mk"
BUILDLINK_API_DEPENDS.mono-addins+=	mono-addins>=0.3.1
.include "../../devel/mono-addins/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
# evolution needs gmime-sharp
#.include "../../mail/evolution/buildlink3.mk"
#.include "../../mail/gmime-sharp/buildlink3.mk"
#.include "../../net/galago-sharp/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-desktop-sharp/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
