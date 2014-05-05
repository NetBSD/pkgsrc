# $NetBSD: Makefile,v 1.39 2014/05/05 00:48:21 ryoon Exp $
#

DISTNAME=	notification-daemon-0.7.6
PKGREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/notification-daemon/0.7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Shows notification messages on the desktop
LICENSE=	gnu-gpl-v2

DEPENDS+=	dbus-[0-9]*:../../sysutils/dbus

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt

.include "../../mk/bsd.prefs.mk"

.if defined(PKG_SYSCONFDIR.dbus)
CONFIGURE_ARGS+=	--with-dbus-sys=${PKG_SYSCONFDIR.dbus}/system.d
.else
CONFIGURE_ARGS+=	--with-dbus-sys=${PKG_SYSCONFDIR}/dbus-1/system.d
.endif

.include "../../audio/libcanberra/buildlink3.mk"
.if empty(PKG_BUILD_OPTIONS.libcanberra:Mgtk3)
PKG_FAIL_REASON+=	"gtk3 option must be enabled for libcanberra."
.endif
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.27.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
