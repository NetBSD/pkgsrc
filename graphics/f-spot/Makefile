# $NetBSD: Makefile,v 1.65 2014/05/05 00:47:55 ryoon Exp $
#

DISTNAME=	f-spot-0.8.2
PKGREVISION=	25
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/f-spot/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://f-spot.org/
COMMENT=	Full-featured personal photo management application

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config bash:run msgfmt

MAKE_JOBS_SAFE=	no

#.include "../../mk/bsd.prefs.mk"
#.for platform in ${LP64PLATFORMS}
#.  if ${MACHINE_PLATFORM:M${platform}}
#CONFIGURE_ENV+=	EXTRACSDEFINES=-define:LONG_IS_64BITS
#.  endif
#.endfor

PKGCONFIG_OVERRIDE+=	f-spot.pc.in

REPLACE_BASH+=	icon-theme-installer
REPLACE_BASH+=	src/Clients/MainApp/f-spot.in
REPLACE_BASH+=	tools/f-spot-import

SUBST_CLASSES+=			fix-x11
SUBST_STAGE.fix-x11=		post-patch
SUBST_MESSAGE.fix-x11=		Fixing libX11 references
SUBST_FILES.fix-x11=		src/Core/FSpot.Utils/FSpot.Utils.dll.config.in
SUBST_FILES.fix-x11+=		src/Core/FSpot.Utils/FSpot.Utils.dll.config
SUBST_FILES.fix-x11+=		build/DllMapVerifier.cs
SUBST_FILES.fix-x11+=		lib/Hyena/build/DllMapVerifier.cs
SUBST_SED.fix-x11=		-e 's,libX11.so.6,${X11BASE}/lib/libX11.so,'

GCONF_SCHEMAS=	f-spot.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../lang/mono2/buildlink3.mk"
.include "../../devel/mono-addins/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gnome-desktop-sharp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../security/gnome-keyring-sharp/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
