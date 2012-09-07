# $NetBSD: Makefile,v 1.77 2012/09/07 19:17:08 adam Exp $
#

DISTNAME=		gok-2.28.1
PKGREVISION=		12
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gok/2.28/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://library.gnome.org/devel/gok/
COMMENT=		GNOME On-Screen Keyboard

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake msgfmt pkg-config intltool
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	gok-1.0.pc.in

GCONF_SCHEMAS=		gok.schemas

.include "../../audio/gnome-speech/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.16.0
.include "../../devel/GConf/schemas.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.17.4
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libSM/buildlink3.mk"
#.include "../../x11/libX11/buildlink3.mk"
#BUILDLINK_DEPMETHOD.libXt?=	build
#.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXevie/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
