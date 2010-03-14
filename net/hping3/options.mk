# $NetBSD: options.mk,v 1.1.1.1 2010/03/14 18:37:58 pettai Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hping3
PKG_SUPPORTED_OPTIONS=		tcl
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
### TCL scripting support
###
.if !empty(PKG_OPTIONS:Mtcl)
.include "../../lang/tcl/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --no-tcl
.endif
