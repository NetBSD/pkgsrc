# $NetBSD: Makefile,v 1.30 2006/09/05 00:55:32 gdt Exp $
#

DISTNAME=	mail-notification-3.0
CATEGORIES=	mail gnome
MASTER_SITES=	http://savannah.nongnu.org/download/mailnotify/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/mailnotify/
COMMENT=	Status icon that provides new mail notifications

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

GCONF2_SCHEMAS=		mail-notification.schemas

PKG_OPTIONS_VAR=	PKG_OPTIONS.mail-notification
PKG_SUPPORTED_OPTIONS=	inet6 sasl ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

# Whether to add IPv6 support.
.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# Whether to add SASL2 support.
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
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
.include "../../mail/gmime/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
