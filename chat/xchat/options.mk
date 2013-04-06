# $NetBSD: options.mk,v 1.16 2013/04/06 19:42:41 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xchat
PKG_SUPPORTED_OPTIONS=	inet6 ssl socks5 mitshm gnome
PKG_OPTIONS_GROUP.spell=	libsexy gtkspell
PKG_OPTIONS_OPTIONAL_GROUPS=	spell
PKG_SUGGESTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dbus

###
### Use OpenSSL libraries for connecting to ircs servers
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openssl=${SSLBASE:Q}
.else
CONFIGURE_ARGS+=	--enable-openssl=no
.endif

###
### Support for connecting thru SOCKS servers
###
.if !empty(PKG_OPTIONS:Msocks5)
CONFIGURE_ARGS+=	--enable-socks
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

###
### MIT-SHM extension support (for "fast tinting")
###
.if !empty(PKG_OPTIONS:Mmitshm)
CONFIGURE_ARGS+=	--enable-shm
.else
CONFIGURE_ARGS+=	--disable-shm
.endif

###
### GNOME support
###
.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-dbus
PLIST.dbus=		yes
SUBST_CLASSES+=		gconf
SUBST_STAGE.gconf=	pre-configure
SUBST_MESSAGE.gconf=	Disabling schema registration/installation.
SUBST_SED.gconf+=	-e 's,DO_GCONF_TRUE,DO_GCONF_FALSE,g'
SUBST_FILES.gconf+=	src/common/dbus/Makefile.in
.	include "../../devel/GConf/schemas.mk"
.	include "../../sysutils/dbus-glib/buildlink3.mk"
.else
# We set this to ${FALSE} to avoid detection.
CONFIGURE_ARGS+=	--disable-dbus
.endif

###
### Support for spell checking
###
.if !empty(PKG_OPTIONS:Mgtkspell)
CONFIGURE_ARGS+=	--enable-spell=gtkspell
.	include "../../textproc/gtkspell/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mlibsexy)
CONFIGURE_ARGS+=	--enable-spell=libsexy
.	include "../../devel/libsexy/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-spell=none
.endif
