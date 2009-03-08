# $NetBSD: Makefile,v 1.3 2009/03/08 15:56:45 wiz Exp $
#

DISTNAME=	f-spot-0.5.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/f-spot/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://f-spot.org/
COMMENT=	Full-featured personal photo management application

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config bash:run
USE_DIRS+=	gnome2-1.6

MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	f-spot.pc.in

REPLACE_BASH+=	icon-theme-installer
REPLACE_BASH+=	src/f-spot.in
REPLACE_BASH+=	tools/f-spot-import

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gnome-desktop-sharp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
