# $NetBSD: Makefile,v 1.24 2012/10/03 00:02:45 asau Exp $
#

DISTNAME=	telepathy-gabble-0.11.10
PKGREVISION=	8
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-gabble/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Components
COMMENT=	Jabber/XMPP connection manager for Telepathy
LICENSE=	gnu-lgpl-v2.1 AND mit

BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
CONFIGURE_ENV+=	UUID_CFLAGS=" " UUID_LIBS=" "

# see pkgsrc/security/mozilla-rootcerts
CONFIGURE_ARGS+=	--with-ca-certificates=/etc/ssl/certs/ca-certificates.crt

# pkgsrc pkg-config wrapper hide *.pc files in source tree with PKG_CONFIG.
BUILDLINK_TARGETS+=	wocky-pkg-config-hack
wocky-pkg-config-hack:
	${LN} -s ${WRKSRC}/lib/ext/wocky/wocky/wocky-uninstalled.pc \
		${BUILDLINK_DIR}/lib/pkgconfig
	${LN} -s ${WRKSRC}/lib/ext/telepathy-yell/telepathy-yell/telepathy-yell-uninstalled.pc \
		${BUILDLINK_DIR}/lib/pkgconfig

BUILDLINK_API_DEPENDS.telepathy-glib+=	telepathy-glib>=0.7.37
.include "../../chat/telepathy-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.21.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../net/libnice/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.78
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=		dbus>=1.1
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
