# $NetBSD: Makefile,v 1.44 2014/05/05 00:48:20 ryoon Exp $
#

DISTNAME=	gnome-system-monitor-2.28.2
PKGREVISION=	20
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-system-monitor/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME 2 system monitor program

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf gmake intltool msgfmt pkg-config
USE_LANGUAGES=		c c++

CONFLICTS+=		gnome2-system-monitor-[0-9]*

.include "../../mk/bsd.prefs.mk"

# XXX: bound this check better
.if ${OPSYS} != "SunOS"
LIBS+=			-lutil
.endif

GCONF_SCHEMAS+=		gnome-system-monitor.schemas

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.14
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.15.3
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.dbus-glib+=	dbus-glib>=0.70
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgtop+=	libgtop>=2.23.1
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.8
.include "../../x11/gtkmm/buildlink3.mk"
# doesn't seem to do anything with it
#.include "../../sysutils/libgksu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
