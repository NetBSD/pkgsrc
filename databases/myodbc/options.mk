# $NetBSD: options.mk,v 1.6 2012/11/22 10:01:10 jnemeth Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.myodbc
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	iodbc unixodbc
PKG_SUPPORTED_OPTIONS=	gui
PKG_SUGGESTED_OPTIONS=	iodbc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gui

.if !empty(PKG_OPTIONS:Mgui)
.  include "../../x11/qt3-tools/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-gui
#USE_LANGUAGES=		c c++
PLIST.gui=		yes
.else
#CONFIGURE_ARGS+=	--disable-gui
.endif

.if !empty(PKG_OPTIONS:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CMAKE_ARGS+=		-DWITH_UNIXODBC=1
.endif
