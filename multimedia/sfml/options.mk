# $NetBSD: options.mk,v 1.1 2020/05/21 08:42:00 plunky Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sfml
PKG_SUPPORTED_OPTIONS=	debug static
PKG_SUGGESTED_OPTIONS=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
MAKE_ENV+=		DEBUGBUILD=yes
.else
MAKE_ENV+=		DEBUGBUILD=no
.endif

.if !empty(PKG_OPTIONS:Mstatic)
MAKE_ENV+=		STATIC=yes
.else
MAKE_ENV+=		STATIC=no
.endif
