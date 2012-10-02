# $NetBSD: Makefile,v 1.31 2012/10/02 17:11:58 tron Exp $
#

DISTNAME=	gnome-power-manager-2.24.4
PKGREVISION=	22
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-power-manager/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/gnome-power-manager/
COMMENT=	GNOME desktop session daemon for managing power management

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-policykit
CONFIGURE_ENV+=		ac_cv_path_DOCBOOK2MAN=no

GCONF_SCHEMAS+=		gnome-power-manager.schemas

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
BUILDLINK_TRANSFORM+=   rm:-lresolv
.endif

.if ${PKGSRC_COMPILER:Mclang}
CFLAGS+=	-Wno-tautological-compare
.endif

# using deprecated g_atexit in glib2.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/GConf/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../security/policykit-gnome/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
