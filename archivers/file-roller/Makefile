# $NetBSD: Makefile,v 1.70 2007/04/19 21:41:03 wiz Exp $
#

DISTNAME=	file-roller-2.18.2
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/file-roller/2.18/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fileroller.sourceforge.net/
COMMENT=	Front-end to archiving programs like tar and zip

DEPENDS+=		gtar-base>=1.13.25:../../archivers/gtar-base
DEPENDS+=		unzip>=5.50nb2:../../archivers/unzip
DEPENDS+=		zip>=2.3nb2:../../archivers/zip

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		file-roller.schemas

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.12.0
BUILDLINK_API_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.10.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.libglade2+=	libglade2>=2.4.0

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
