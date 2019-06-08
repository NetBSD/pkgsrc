# $NetBSD: options.mk,v 1.2 2019/06/08 10:53:28 rillig Exp $
### Set options
PKG_OPTIONS_VAR=	PKG_OPTIONS.nios2-binutils
PKG_SUPPORTED_OPTIONS=	sysroot
PKG_SUGGESTED_OPTIONS=	sysroot

.include "../../mk/bsd.options.mk"

.if  !empty(PKG_OPTIONS:Msysroot)
CONFIGURE_ARGS+=	--with-sysroot
.endif
