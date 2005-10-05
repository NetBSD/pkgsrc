# $NetBSD: options.mk,v 1.3 2005/10/05 13:29:49 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.db4
PKG_SUPPORTED_OPTIONS=	java

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjava)
CONFIGURE_ARGS+=	--enable-java
.  include "../../mk/java-vm.mk"
.else
CONFIGURE_ARGS+=	--disable-java
.endif
