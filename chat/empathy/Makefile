# $NetBSD: Makefile,v 1.46 2012/12/15 10:36:21 ryoon Exp $

DISTNAME=	empathy-2.34.0
PKGREVISION=	21
CATEGORIES=	chat gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/empathy/2.34/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Empathy
COMMENT=	Gnome instant messenger client
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gawk gmake gsed intltool msgfmt pkg-config
USE_TOOLS+=		autoconf
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ENV+=	YELL_CFLAGS=-I${WRKSRC}/telepathy-yell
CONFIGURE_ENV+=	\
  YELL_LIBS="-L${WRKSRC}/telepathy-yell/telepathy-yell -ltelepathy-yell"

# see pkgsrc/security/mozilla-rootcerts
CONFIGURE_ARGS+=	--with-ca-file=/etc/ssl/certs/ca-certificates.crt

BUILDLINK_TRANSFORM+=	rm:-Werror

# notyet
#CONFIGURE_ARGS+=	--enable-meego

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../chat/telepathy-farsight/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../chat/telepathy-logger/buildlink3.mk"
.include "../../chat/libfolks/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.enchant+=		enchant>=1.2.0
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
# notyet
#.include "../../www/webkit-gtk/buildlink3.mk"
#.include "../../graphics/clutter-mx/buildlink3.mk"
#.include "../../chat/telepathy-logger/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
