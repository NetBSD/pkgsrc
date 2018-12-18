# $NetBSD: options.mk,v 1.4 2018/12/18 06:46:39 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.z3
PKG_SUPPORTED_OPTIONS=	ocaml java
PKG_SUGGESTED_OPTIONS=	ocaml

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ocaml java
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
PLIST.java=		yes
.endif
