# $NetBSD: Makefile,v 1.72 2018/11/14 22:22:15 kleink Exp $

DISTNAME=	gnome-packagekit-0.4.0
PKGREVISION=	56
CATEGORIES=	pkgtools gnome
MASTER_SITES=	http://www.packagekit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.packagekit.org/
COMMENT=	GNOME frontend for PackageKit
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake intltool perl msgfmt
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS+=	gnome-packagekit.schemas

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.4.0

# needed for gnome-packagekit-0.4 and gtk2-2.20 -- remove on next update
BUILDLINK_TRANSFORM+=		rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=		rm:-DGDK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=		rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=		rm:-DGTK_DISABLE_DEPRECATED
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.30.0

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../pkgtools/packagekit/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/policykit-gnome/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
