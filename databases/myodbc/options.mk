# $NetBSD: options.mk,v 1.2 2006/07/22 04:46:14 rillig Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.myodbc
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	myodbc-iodbc myodbc-unixodbc
PKG_SUPPORTED_OPTIONS=	myodbc-gui
PKG_SUGGESTED_OPTIONS=	myodbc-iodbc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmyodbc-gui)
.  include "../../x11/qt3-tools/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gui
USE_LANGUAGES=		c c++
PLIST_SUBST+=		WITH_GUI=
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUBST+=		WITH_GUI='@comment '
.endif

.if !empty(PKG_OPTIONS:Mmyodbc-iodbc)
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-iodbc=${BUILDLINK_PREFIX.iodbc}
CONFIGURE_ARGS+=	--with-odbc-ini=${PKG_SYSCONFDIR.iodbc}/odbc.ini
.endif

.if !empty(PKG_OPTIONS:Mmyodbc-unixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-unixODBC=${BUILDLINK_PREFIX.unixodbc}
CONFIGURE_ARGS+=	--with-odbc-ini=${PKG_SYSCONFDIR.unixodbc}/odbc.ini
.endif
