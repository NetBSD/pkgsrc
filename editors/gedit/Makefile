# $NetBSD: Makefile,v 1.67 2006/09/15 15:21:49 jmmv Exp $
#

DISTNAME=		gedit-2.16.0
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gedit/2.16/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gedit.sourceforge.net/
COMMENT=		Lightweight GNOME2 text editor

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

PKGCONFIG_OVERRIDE+=	data/gedit.pc.in

GCONF2_SCHEMAS=		gedit.schemas

CONFIGURE_ARGS+=	--enable-schemas-install

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.12.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.gtksourceview+=	gtksourceview>=1.8.0
BUILDLINK_API_DEPENDS.libglade2+=	libglade2>=2.6.0
BUILDLINK_API_DEPENDS.libgnomeprintui+=	libgnomeprintui>=2.12.1
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.16.0
BUILDLINK_API_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.16.0

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
