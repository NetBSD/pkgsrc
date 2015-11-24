# $NetBSD: options.mk,v 1.1 2015/11/24 05:45:58 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.z3
PKG_SUPPORTED_OPTIONS=	ocaml java
PKG_SUGGESTED_OPTIONS=	ocaml

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mocaml)
CONFIGURE_ARGS+=	--ml
.include "../../lang/ocaml/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjava)
# XXX untested
USE_JAVA=	yes
CONFIGURE_ARGS+=	--java
.include "../../mk/java-vm.mk"
.endif
