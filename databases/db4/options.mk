# $NetBSD: options.mk,v 1.1 2004/12/27 04:27:49 jlam Exp $

.if defined(WITH_JAVA) && !empty(WITH_JAVA:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	java
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.db4
PKG_SUPPORTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
CONFIGURE_ARGS+=	--enable-java
.  include "../../mk/java-vm.mk"
.else
CONFIGURE_ARGS+=	--disable-java
.endif
