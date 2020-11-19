# $NetBSD: options.mk,v 1.2 2020/11/19 20:01:40 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amule
PKG_SUPPORTED_OPTIONS=	amule-monolithic
PKG_SUPPORTED_OPTIONS+=	amule-gui amule-daemon amule-cmd amule-webserver
PKG_SUPPORTED_OPTIONS+=	amule-cas amule-wxcas amule-ed2k amule-alc amule-alcc
PKG_SUPPORTED_OPTIONS+=	debug geoip upnp
PKG_SUGGESTED_OPTIONS=	amule-monolithic amule-ed2k upnp

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	skins alc alcc amule ed2k daemon gui cmd web cas wxcas

###
### monolithic aMule app
###
.if !empty(PKG_OPTIONS:Mamule-monolithic)
CONFIGURE_ARGS+=	--enable-monolithic
PLIST.amule=		yes
PLIST.skins=		yes
.else
CONFIGURE_ARGS+=	--disable-monolithic
.endif

###
### aMule daemon version
###
.if !empty(PKG_OPTIONS:Mamule-daemon)
CONFIGURE_ARGS+=	--enable-amule-daemon
PLIST.daemon=		yes
.else
CONFIGURE_ARGS+=	--disable-amule-daemon
.endif

###
### aMule remote GUI
###
.if !empty(PKG_OPTIONS:Mamule-gui)
CONFIGURE_ARGS+=	--enable-amule-gui
PLIST.gui=		yes
PLIST.skins=		yes
.else
CONFIGURE_ARGS+=	--disable-amule-gui
.endif

###
### aMule command line client
###
.if !empty(PKG_OPTIONS:Mamule-cmd)
CONFIGURE_ARGS+=	--enable-amulecmd
PLIST.cmd=		yes
.else
CONFIGURE_ARGS+=	--disable-amulecmd
.endif

###
### aMule WebServer
###
.if !empty(PKG_OPTIONS:Mamule-webserver)
CONFIGURE_ARGS+=	--enable-webserver
PLIST.web=		yes
.else
CONFIGURE_ARGS+=	--disable-webserver
.endif

###
### C aMule Statistics
###
.if !empty(PKG_OPTIONS:Mamule-cas)
.include "../../graphics/gd/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cas
CONFIGURE_ARGS+=	--with-gdlib-config=${BUILDLINK_PREFIX.gd}/bin/gdlib-config
PLIST.cas=		yes
.else
CONFIGURE_ARGS+=	--disable-cas
.endif

###
### aMule GUI Statistics
###
.if !empty(PKG_OPTIONS:Mamule-wxcas)
CONFIGURE_ARGS+=	--enable-wxcas
PLIST.wxcas=		yes
.else
CONFIGURE_ARGS+=	--disable-wxcas
.endif

###
### aMule ed2k links handler
###
.if !empty(PKG_OPTIONS:Mamule-ed2k)
CONFIGURE_ARGS+=	--enable-ed2k
PLIST.ed2k=		yes
.else
CONFIGURE_ARGS+=	--disable-ed2k
.endif

###
### aMule LinkCreator GUI version
###
.if !empty(PKG_OPTIONS:Mamule-alc)
CONFIGURE_ARGS+=	--enable-alc
PLIST.alc=		yes
.else
CONFIGURE_ARGS+=	--disable-alc
.endif

###
### aMule LinkCreator for console
###
.if !empty(PKG_OPTIONS:Mamule-alcc)
CONFIGURE_ARGS+=	--enable-alcc
PLIST.alcc=		yes
.else
CONFIGURE_ARGS+=	--disable-alcc
.endif

###
### Additional debugging output
###
.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

###
### GeoIP IP2Country support
###
.if !empty(PKG_OPTIONS:Mgeoip)
.include "../../net/GeoIP/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-geoip
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

###
### UPnP support
###
.if !empty(PKG_OPTIONS:Mupnp)
BUILDLINK_API_DEPENDS.libupnp+=	libupnp>=1.6.6
.include "../../net/libupnp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-upnp
CONFIGURE_ARGS+=	--with-libupnp-prefix=${BUILDLINK_PREFIX.libupnp}
.else
CONFIGURE_ARGS+=	--disable-upnp
.endif

.if !empty(PKG_OPTIONS:Mamule-alc) || \
	!empty(PKG_OPTIONS:Mamule-monolithic) || \
	!empty(amule-wxcas) || \
	!empty(amule-gui)
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.endif
