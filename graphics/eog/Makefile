# $NetBSD: Makefile,v 1.95 2018/11/14 22:21:37 kleink Exp $

DISTNAME=	eog-2.32.1
PKGREVISION=	28
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/eog/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Eye of GNOME: an image viewing and cataloging program
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		yes

GCONF_SCHEMAS=	eog.schemas

# XXX Python plugins do more harm than good for now
#.include "../../lang/python/application.mk"
#.include "../../x11/py-gtk2/buildlink3.mk"
#PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../devel/eel/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-icon-theme+= gnome-icon-theme>=2.20.0
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
BUILDLINK_API_DEPENDS.libexif+=	libexif>=0.6.12
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.shared-mime-info+= shared-mime-info>=0.20
.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.71
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.11.6
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
