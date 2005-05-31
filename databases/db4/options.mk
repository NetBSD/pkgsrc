# $NetBSD: options.mk,v 1.2 2005/05/31 10:01:36 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.db4
PKG_SUPPORTED_OPTIONS=	java
PKG_OPTIONS_LEGACY_VARS+=	WITH_JAVA:java

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
CONFIGURE_ARGS+=	--enable-java
.  include "../../mk/java-vm.mk"
.else
CONFIGURE_ARGS+=	--disable-java
.endif
