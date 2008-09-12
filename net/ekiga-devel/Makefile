# $NetBSD: Makefile,v 1.1.1.1 2008/09/12 13:24:51 jmcneill Exp $
#

DISTNAME=		ekiga-snapshot-20080907
PKGNAME=		ekiga-2.9.90.20080907
COMMENT=		VoIP and video conferencing application for GNOME
CATEGORIES=		net comms
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ekiga.org/
MASTER_SITES=		http://snapshots.ekiga.net/snapshots/sources/archives/

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_TOOLS+=		autoconf automake aclocal
USE_PKGLOCALEDIR=	yes

TOOLS_ALIASES.automake+=	automake-1.10
TOOLS_ALIASES.aclocal+=		aclocal-1.10

CONFIGURE_ARGS+=	--disable-avahi

GCONF_SCHEMAS=		ekiga.schemas

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

WRKSRC=			${WRKDIR}/ekiga

pre-configure:
	cd ${WRKSRC} && gnome-autogen.sh ${CONFIGURE_ARGS}

BUILD_DEPENDS+=gnome-common>=2.20.0:../../devel/gnome-common

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../audio/esound/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../devel/ptlib/buildlink3.mk"
.include "../../devel/opal-devel/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
