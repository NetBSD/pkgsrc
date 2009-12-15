# $NetBSD: options.mk,v 1.3 2009/12/15 12:07:57 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.erlang
PKG_SUPPORTED_OPTIONS=	java erlang-hipe
PKG_OPTIONS_OPTIONAL_GROUPS=	odbc
PKG_OPTIONS_GROUP.odbc=		iodbc unixodbc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
USE_JAVA=		yes
USE_JAVA2=		yes
.include "../../mk/java-vm.mk"
PLIST_SRC+=		PLIST.java
.else
CONFIGURE_ENV+=	JAVAC=none
.endif

.if !empty(PKG_OPTIONS:Merlang-hipe)
###
### XXX Need to check which platforms will enable this by default, if any.
###	Should it be an option?
###
PLIST_SUBST+=		SMP="@comment "
CONFIGURE_ARGS+=	--enable-hipe
.else
PLIST_SUBST+=		SMP=""
CONFIGURE_ARGS+=	--disable-hipe
.endif

###
### Provide iodbc/unixodbc option support
###
.if !empty(PKG_OPTIONS:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-odbc=${BUILDLINK_PREFIX.iodbc}
PLIST_SRC+=		PLIST.odbc
.endif

.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-odbc=${BUILDLINK_PREFIX.unixodbc}
PLIST_SRC+=		PLIST.odbc
.endif
