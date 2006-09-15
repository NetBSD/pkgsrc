# $NetBSD: Makefile,v 1.57 2006/09/15 15:20:16 jmmv Exp $
#

DISTNAME=		yelp-2.16.0
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/yelp/2.16/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Help browser for GNOME 2 desktop

DEPENDS+=		docbook>=4.2:../../textproc/docbook

BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.4

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-html-widget=gtkhtml2

GCONF2_SCHEMAS=		yelp.schemas

PKG_OPTIONS_VAR=	PKG_OPTIONS.yelp
.include "../../www/mozilla/gecko-options.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfirefox)
# Require a version that has the .pc files in it.
BUILDLINK_API_DEPENDS.firefox+=     firefox>=1.5nb2
.endif
BUILDLINK_API_DEPENDS.gtk2+=     		gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.libgnome+=		libgnome>=2.14.0
BUILDLINK_API_DEPENDS.libgnomeui+=		libgnomeui>=2.14.0
BUILDLINK_API_DEPENDS.startup-notification+=	startup-notification>=0.8
BUILDLINK_API_DEPENDS.libxml2+=			libxml2>=2.6.5

BUILDLINK_DEPMETHOD.gnome-doc-utils+=   run

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/mozilla/gecko-depends.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
