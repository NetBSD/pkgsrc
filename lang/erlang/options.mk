# $NetBSD: options.mk,v 1.4 2011/04/14 19:34:07 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.erlang
PKG_SUPPORTED_OPTIONS=	java erlang-hipe
PKG_OPTIONS_OPTIONAL_GROUPS=	odbc
PKG_OPTIONS_GROUP.odbc=		iodbc unixodbc

PKG_SUGGESTED_OPTIONS=	# empty
###
### Activate HiPE by default on some systems or if the user has
### defined the erlang-hipe option in mk.conf
###
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") &&	\
    (${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" ||			\
     ${OPSYS} == "NetBSD"  || ${OPSYS} == "OpenBSD")
PKG_SUGGESTED_OPTIONS+=	erlang-hipe
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	odbc

.if !empty(PKG_OPTIONS:Mjava)
USE_JAVA=		yes
USE_JAVA2=		yes
.include "../../mk/java-vm.mk"
PLIST_SRC+=		PLIST.java
.else
CONFIGURE_ARGS+=	--without-javac
.endif

.if !empty(PKG_OPTIONS:Merlang-hipe)
CONFIGURE_ARGS+=	--enable-hipe
PLIST_SRC+=		PLIST.hipe
.else
CONFIGURE_ARGS+=	--disable-hipe
.endif

###
### Provide iodbc/unixodbc option support
###
.if !empty(PKG_OPTIONS:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-odbc=${BUILDLINK_PREFIX.iodbc}
PLIST.odbc=	yes
.endif

.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-odbc=${BUILDLINK_PREFIX.unixodbc}
PLIST.odbc=	yes
.endif

# Help generate optional PLIST parts:
PRINT_PLIST_AWK+=	{if ($$0 ~ /\/erlang\/lib\/hipe-${VERSION.hipe}\//) {$$0 = "$${PLIST.hipe}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /\/erlang\/lib\/odbc-${VERSION.odbc}\//) {$$0 = "$${PLIST.odbc}" $$0;}}
