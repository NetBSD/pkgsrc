# $NetBSD: Makefile,v 1.29 2005/03/22 16:30:36 jmmv Exp $
#

DISTNAME=		gconf-editor-2.10.0
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gconf-editor/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Editor for the GConf configuration system

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1 gnome2-1.5
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11=		YES

CONFIGURE_ARGS+=	--with-gconf-defaults-source=${GCONF2_CONFIG_SOURCE}
CONFIGURE_ARGS+=	--with-gconf-mandatory-source=${GCONF2_CONFIG_SOURCE:S/gconf.xml.defaults/gconf.xml.mandatory/g}

GCONF2_SCHEMAS=		gconf-editor.schemas

BUILDLINK_DEPENDS.GConf2+=	GConf2>=2.10.0

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
