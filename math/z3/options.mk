# $NetBSD: options.mk,v 1.2 2018/03/11 06:14:45 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.z3
PKG_SUPPORTED_OPTIONS=	ocaml java
PKG_SUGGESTED_OPTIONS=	ocaml

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mocaml)
CONFIGURE_ARGS+=	--ml
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjava)
# XXX untested
USE_JAVA=	yes
CONFIGURE_ARGS+=	--java
.include "../../mk/java-vm.mk"
.endif
