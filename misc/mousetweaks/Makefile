# $NetBSD: Makefile,v 1.4 2009/03/03 12:58:25 hasso Exp $
#

DISTNAME=	mousetweaks-2.24.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/mousetweaks/2.24/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Mousetweaks/Home
COMMENT=	Mouse accessibility software

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/

GCONF_SCHEMAS+=	mousetweaks.schemas
GCONF_SCHEMAS+=	pointer-capture-applet.schemas

USE_TOOLS+=	gmake intltool msgfmt pkg-config
USE_DIRS+=	gnome2-1.6

BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.16.0
.include "../../devel/GConf/schemas.mk"
.include "../../devel/at-spi/buildlink3.mk"
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.4.0
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/rarian/omf.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.13.1
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
