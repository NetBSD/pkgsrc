# $NetBSD: Makefile,v 1.1.1.1 2009/01/08 00:22:45 jmcneill Exp $
#

DISTNAME=	gnome-packagekit-0.4.0
CATEGORIES=	pkgtools gnome
MASTER_SITES=	http://www.packagekit.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.packagekit.org/
COMMENT=	GNOME frontend for PackageKit

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
MAKE_ENV+=	GCONF_SCHEMA_FILE_DIR=${PREFIX}/share/gconf/schemas/
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool perl msgfmt
USE_DIRS+=	gnome2-1.6
USE_PKGLOCALEDIR= yes

GCONF_SCHEMAS+=	gnome-packagekit.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../pkgtools/packagekit/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/policykit-gnome/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
