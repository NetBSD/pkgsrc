# $NetBSD: Makefile,v 1.118 2012/10/02 17:10:54 tron Exp $
#

DISTNAME=		gedit-2.30.4
PKGREVISION=		10
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

PKGCONFIG_OVERRIDE+=	data/gedit.pc.in

GCONF_SCHEMAS=		gedit.schemas gedit-file-browser.schemas

.include "options.mk"

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
