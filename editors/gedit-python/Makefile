# $NetBSD: Makefile,v 1.12 2012/10/02 17:10:54 tron Exp $
#

DISTNAME=		gedit-2.30.4
PKGNAME=		gedit-python-2.30.4
PKGREVISION=		11
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gedit/2.30/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/gedit/
COMMENT=		Lightweight GNOME2 text editor
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-spell
CONFIGURE_ARGS+=	--enable-python

PATCHDIR=	${.CURDIR}/../../editors/gedit/patches
DISTINFO_FILE=	${.CURDIR}/../../editors/gedit/distinfo
BUILD_DIRS=	plugin-loaders/python
BUILD_DIRS+=	plugins/pythonconsole plugins/quickopen plugins/snippets
INSTALL_DIRS=	${BUILD_DIRS}

.include "../../lang/python/application.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.py_gtksourceview+= ${PYPKGPREFIX}-gtksourceview>=2.10.1
.include "../../x11/py-gtksourceview/buildlink3.mk"
.include "../../editors/gedit/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.13.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.2.0
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
