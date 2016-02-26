# $NetBSD: options.mk,v 1.3 2016/02/26 16:03:09 fhajny Exp $

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

# The prospect of using databases/wiredtiger is unclear yet;
# MongoDB doesn't provide guarantees for non-bundled WiredTiger:
# https://groups.google.com/forum/#!msg/mongodb-dev/31FQSo4KVCI/Fx-WtJ9fzU4J
.if !empty(PKG_OPTIONS:Mwiredtiger)
.  if empty(MACHINE_ARCH:Mx86_64)
PKG_FAIL_REASON+=	"WiredTiger is not supported on 32-bit platforms"
.  endif
SCONS_ARGS+=		--wiredtiger=on
.else
SCONS_ARGS+=		--wiredtiger=off
.endif
