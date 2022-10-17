# $NetBSD: options.mk,v 1.15 2022/10/17 01:47:17 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.erlang
PKG_SUPPORTED_OPTIONS=		java
PKG_OPTIONS_OPTIONAL_GROUPS=	odbc
PKG_OPTIONS_GROUP.odbc=		iodbc unixodbc

PKG_SUGGESTED_OPTIONS=	# empty

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	dtrace
.endif

.include "../../mk/bsd.options.mk"

PLIST_SRC=	${PLIST_SRC_DFLT}
PLIST_VARS+=	odbc

.if !empty(PKG_OPTIONS:Mjava)
USE_JAVA=		yes
USE_JAVA2=		yes
.include "../../mk/java-vm.mk"
PLIST_SRC+=		PLIST.java
.else
CONFIGURE_ARGS+=	--without-javac
.endif

###
### Provide iodbc/unixodbc option support
###
.if !empty(PKG_OPTIONS:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-odbc=${BUILDLINK_PREFIX.iodbc}
PLIST.odbc=	yes
.elif !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-odbc=${BUILDLINK_PREFIX.unixodbc}
PLIST.odbc=	yes
.else
CONFIGURE_ARGS+=	--without-odbc
.endif

###
### DTrace support
###
.if !empty(PKG_OPTIONS:Mdtrace)
.  if ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin" || ${OPSYS} == "FreeBSD"
CONFIGURE_ARGS+=	--with-dynamic-trace=dtrace
.  elif ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-dynamic-trace=systemtap
.  endif
.else
CONFIGURE_ARGS+=	--without-dynamic-trace
.endif

# Help generate optional PLIST parts:
PRINT_PLIST_AWK+=	{if ($$0 ~ /dtrace_user/) {$$0 = "$${PLIST.dtrace}" $$0;}}
PRINT_PLIST_AWK+=	{if ($$0 ~ /\/erlang\/lib\/odbc-${VERSION.odbc}\//) {$$0 = "$${PLIST.odbc}" $$0;}}
