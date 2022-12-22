# $NetBSD: options.mk,v 1.1 2022/12/22 06:26:20 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.glw
PKG_SUPPORTED_OPTIONS+=	motif
PKG_SUGGESTED_OPTIONS=	motif

.include "../../mk/bsd.options.mk"

##
## Enable Motif:
## XmPrimitive widget class support.
##
.if !empty(PKG_OPTIONS:Mmotif)
.  include "../../mk/motif.buildlink3.mk"
#CFLAGS+=    -D__GLX_MOTIF=1
CONFIGURE_ARGS+=   --enable-motif
.endif
