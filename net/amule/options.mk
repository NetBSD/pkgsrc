# $NetBSD: options.mk,v 1.3 2026/06/24 13:37:09 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amule
PKG_SUPPORTED_OPTIONS=	amule-cas amule-monolithic
PKG_SUPPORTED_OPTIONS+=	amule-gui amule-daemon amule-cmd amule-webserver
PKG_SUPPORTED_OPTIONS+=	amule-wxcas amule-ed2k amule-alc amule-alcc geoip
PKG_SUGGESTED_OPTIONS=	amule-monolithic amule-ed2k

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alc alcc amule cas cmd ed2k daemon gui skins web wxcas

###
### monolithic aMule app
###
.if !empty(PKG_OPTIONS:Mamule-monolithic)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_MONOLITHIC=ON
PLIST.amule=		yes
PLIST.skins=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_MONOLITHIC=OFF
.endif

###
### aMule daemon version
###
.if !empty(PKG_OPTIONS:Mamule-daemon)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_DAEMON=ON
PLIST.daemon=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_DAEMON=OFF
.endif

###
### aMule remote GUI
###
.if !empty(PKG_OPTIONS:Mamule-gui)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_REMOTEGUI=ON
PLIST.gui=		yes
PLIST.skins=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_REMOTEGUI=OFF
.endif

###
### aMule command line client
###
.if !empty(PKG_OPTIONS:Mamule-cmd)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_AMULECMD=ON
PLIST.cmd=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_AMULECMD=OFF
.endif

###
### aMule WebServer
###
.if !empty(PKG_OPTIONS:Mamule-webserver)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WEBSERVER=ON
PLIST.web=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WEBSERVER=OFF
.endif

###
### C aMule Statistics
###
.if !empty(PKG_OPTIONS:Mamule-cas)
.include "../../graphics/gd/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DBUILD_CAS=ON
PLIST.cas=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_CAS=OFF
.endif

###
### aMule GUI Statistics
###
.if !empty(PKG_OPTIONS:Mamule-wxcas)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WXCAS=ON
PLIST.wxcas=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WXCAS=OFF
.endif

###
### aMule ed2k links handler
###
.if !empty(PKG_OPTIONS:Mamule-ed2k)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ED2K=ON
PLIST.ed2k=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ED2K=OFF
.endif

###
### aMule LinkCreator GUI version
###
.if !empty(PKG_OPTIONS:Mamule-alc)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ALC=ON
PLIST.alc=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ALC=OFF
.endif

###
### aMule LinkCreator for console
###
.if !empty(PKG_OPTIONS:Mamule-alcc)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ALCC=ON
PLIST.alcc=		yes
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ALCC=OFF
.endif

###
### GeoIP IP2Country support
###
.if !empty(PKG_OPTIONS:Mgeoip)
.include "../../geography/libmaxminddb/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DENABLE_IP2COUNTRY=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_IP2COUNTRY=OFF
.endif

.if !empty(PKG_OPTIONS:Mamule-alc) || \
	!empty(PKG_OPTIONS:Mamule-monolithic) || \
	!empty(amule-wxcas) || \
	!empty(amule-gui)
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.endif
