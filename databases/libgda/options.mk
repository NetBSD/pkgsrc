# $NetBSD: options.mk,v 1.1 2007/08/04 11:13:37 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libgda
PKG_SUPPORTED_OPTIONS=	fam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
.endif
