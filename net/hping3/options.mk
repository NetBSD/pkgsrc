# $NetBSD: options.mk,v 1.2 2017/06/14 12:17:30 jperkin Exp $

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
CONFIGURE_ENV+=		TCLSH=/nonexistent
.endif
