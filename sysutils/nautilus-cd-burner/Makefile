# $NetBSD: Makefile,v 1.60 2010/06/13 22:45:24 wiz Exp $
#

DISTNAME=	nautilus-cd-burner-2.24.0
PKGREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-cd-burner/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	CD burner view for Nautilus

DEPENDS+=		cdrtools-[0-9]*:../../sysutils/cdrtools

USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE=	libnautilus-burn.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	schemadir=${GCONF_SCHEMAS_DIR}

GCONF_SCHEMAS=		nautilus-cd-burner.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.eel+=	eel>=2.13.3
.include "../../devel/eel/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.4
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.14.0
.include "../../devel/libgnome/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.14.0
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-mount/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
BUILDLINK_API_DEPENDS.nautilus+=	nautilus>=2.22.2
.include "../../sysutils/nautilus/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.5.4
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
