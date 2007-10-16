# $NetBSD: options.mk,v 1.2 2007/10/16 21:33:00 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.emacs
PKG_SUPPORTED_OPTIONS=		emacs-pop inet6 x11
PKG_OPTIONS_OPTIONAL_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	motif xaw
PKG_SUGGESTED_OPTIONS=		emacs-pop inet6

.include "../../mk/bsd.options.mk"

###
### Support POP connections for retrieving mail.
###
.if !empty(PKG_OPTIONS:Memacs-pop)
CONFIGURE_ARGS+=	--with-pop
.endif

###
### Support IPv6 connections.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

###
### Any of the "toolkit" options implies "x11".
###
.if !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mxaw)
.  if empty(PKG_OPTIONS:Mx11)
PKG_OPTIONS+=		x11
.  endif
.endif

###
### Default to using the Xaw X11 toolkit if none is specified.
###
.if !empty(PKG_OPTIONS:Mx11)
.  if empty(PKG_OPTIONS:Mmotif) && empty(PKG_OPTIONS:Mxaw)
PKG_OPTIONS+=		xaw
.  endif
.endif

###
### Support drawing pretty X11 widgets.
###
.if !empty(PKG_OPTIONS:Mx11)
USE_TOOLS+=		imake
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

###
### Support using Motif X11 widgets.
###
.if !empty(PKG_OPTIONS:Mmotif)
.  include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.endif

###
### Support using Xaw (Lucid) X11 widgets.
###
.if !empty(PKG_OPTIONS:Mxaw)
.  include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.endif
