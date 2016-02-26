# $NetBSD: options.mk,v 1.2 2016/02/26 12:33:26 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongodb
PKG_SUPPORTED_OPTIONS=	ssl wiredtiger
PKG_SUGGESTED_OPTIONS=	#

.if !empty(MACHINE_ARCH:Mx86_64)
PKG_SUGGESTED_OPTIONS+=	wiredtiger
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
SCONS_ARGS+=		--ssl
.endif

.if !empty(PKG_OPTIONS:Mwiredtiger)
.  if empty(MACHINE_ARCH:Mx86_64)
PKG_FAIL_REASON+=	"WiredTiger is not supported on 32-bit platforms"
.  endif
SCONS_ARGS+=		--wiredtiger=on
.else
SCONS_ARGS+=		--wiredtiger=off
.endif
