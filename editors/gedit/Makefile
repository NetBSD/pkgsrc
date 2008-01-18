# $NetBSD: Makefile,v 1.79 2008/01/18 05:06:32 tnn Exp $
#

DISTNAME=		gedit-2.20.4
PKGREVISION=		1
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gedit/2.20/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/gedit/
COMMENT=		Lightweight GNOME2 text editor

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE+=	data/gedit.pc.in

GCONF_SCHEMAS=		gedit.schemas

CONFIGURE_ARGS+=	--enable-schemas-install
# XXX option?
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
#CONFIGURE_ARGS+=	--disable-spell

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.12.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0
#BUILDLINK_API_DEPENDS.gtksourceview+=	gtksourceview>=1.8.0
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.6.0
BUILDLINK_API_DEPENDS.libgnomeprintui+=	libgnomeprintui>=2.12.1
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.16.0
BUILDLINK_API_DEPENDS.gnome-vfs+=	gnome-vfs>=2.16.0

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
