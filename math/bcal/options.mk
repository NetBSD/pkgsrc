# $NetBSD: options.mk,v 1.1 2026/09/07 21:44:14 sjmulder Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bcal
PKG_OPTIONS_OPTIONAL_GROUPS=	editing
PKG_OPTIONS_GROUP.editing=	readline editline
PKG_SUGGESTED_OPTIONS=		readline

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Meditline)
MAKE_FLAGS+=	O_EL=1
.  include "../../devel/editline/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mreadline)
.  include "../../mk/readline.buildlink3.mk"
.else
MAKE_FLAGS+=	O_NORL=1
.endif
