# $NetBSD: Makefile,v 1.2 2004/10/03 00:12:53 tv Exp $
#

DISTNAME=	mail-notification-0.6.2
PKGREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://savannah.nongnu.org/download/mailnotify/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/mailnotify/
COMMENT=	Status icon that provides new mail notifications

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

GCONF2_SCHEMAS=		mail-notification.schemas

EGDIR=		${PREFIX}/share/examples/mail-notification
CONF_FILES=	${EGDIR}/sound/events/mail-notification.soundlist \
		${PKG_SYSCONFDIR}/sound/events/mail-notification.soundlist

PKG_OPTIONS_VAR=	PKG_OPTIONS.mail-notification
PKG_SUPPORTED_OPTIONS=	ipv6 sasl ssl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# Whether to add IPv6 support.
.if empty(PKG_OPTIONS:Mipv6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# Whether to add SASL2 support.
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sasl
.endif

# Whether to add SSL support.
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
