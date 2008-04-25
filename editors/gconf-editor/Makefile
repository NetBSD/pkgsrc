# $NetBSD: Makefile,v 1.59 2008/04/25 08:19:52 wiz Exp $
#

DISTNAME=		gconf-editor-2.22.0
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gconf-editor/2.22/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Editor for the GConf configuration system

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1 gnome2-1.5
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--with-gconf-defaults-source=${GCONF_CONFIG_SOURCE:Q}
CONFIGURE_ARGS+=	--with-gconf-mandatory-source=${GCONF_CONFIG_SOURCE:S/gconf.xml.defaults/gconf.xml.mandatory/g}

GCONF_SCHEMAS=		gconf-editor.schemas

BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.14.0
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.14.0

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
