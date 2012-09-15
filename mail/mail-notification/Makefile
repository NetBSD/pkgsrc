# $NetBSD: Makefile,v 1.68 2012/09/15 10:05:28 obache Exp $
#

DISTNAME=	mail-notification-5.4
PKGREVISION=	17
CATEGORIES=	mail gnome
MASTER_SITES=	http://savannah.nongnu.org/download/mailnotify/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/mailnotify/
COMMENT=	Status icon that provides new mail notifications

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./jb configure
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
LDFLAGS+=		-lX11

CONFIGURE_ARGS=		prefix="${PREFIX}" destdir="${DESTDIR}" sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	cc="${CC}" cflags="${CFLAGS}" cppflags="${CPPFLAGS}" ldflags="${LDFLAGS}"
CONFIGURE_ENV+=		jb_cppflags="${CPPFLAGS}" jb_ldflags="${LDFLAGS}"

GCONF_SCHEMAS=		mail-notification.schemas

CONFIGURE_ARGS+=	evolution=no

PKG_OPTIONS_VAR=	PKG_OPTIONS.mail-notification
PKG_SUPPORTED_OPTIONS=	inet6 sasl ssl
PKG_SUGGESTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

# Whether to add IPv6 support.
.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	ipv6=no
.endif

# Whether to add SASL2 support.
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	sasl=no
.endif

# Whether to add SSL support.
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	ssl=no
.endif

do-build:
	cd ${WRKSRC} && ./jb build

do-install:
	cd ${WRKSRC} && ./jb install

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/gmime24/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
