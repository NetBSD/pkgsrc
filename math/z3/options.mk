# $NetBSD: options.mk,v 1.3 2018/03/13 00:31:16 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.z3
PKG_SUPPORTED_OPTIONS=	ocaml java
PKG_SUGGESTED_OPTIONS=	ocaml

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ocaml
.if !empty(PKG_OPTIONS:Mocaml)
CONFIGURE_ARGS+=	--ml
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
PLIST.ocaml=		yes
.endif

.if !empty(PKG_OPTIONS:Mjava)
# XXX untested
USE_JAVA=	yes
CONFIGURE_ARGS+=	--java
.include "../../mk/java-vm.mk"
.endif
