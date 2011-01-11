# $NetBSD: Makefile,v 1.8 2011/01/11 20:46:16 gls Exp $
#

DISTNAME=		shotwell-0.8.0
CATEGORIES=		graphics
MASTER_SITES=		http://yorba.org/download/shotwell/0.8/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgrsc-users@NetBSD.org
HOMEPAGE=		http://yorba.org/shotwell/
COMMENT=		Shotwell is a photo organizer for the GNOME desktop
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake bash pkg-config

CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--assume-pkgs
CONFIGURE_ENV+=		--define=NO_CAMERA

REPLACE_SH+=		minver configure libraw-config

GCONF_SCHEMAS=		shotwell.schemas
INSTALLATION_DIRS+=	share/gconf/schemas

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/shotwell.schemas \
		${DESTDIR}${PREFIX}/share/gconf/schemas

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libgexiv2/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
