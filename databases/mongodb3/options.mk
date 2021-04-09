# $NetBSD: options.mk,v 1.3 2021/04/09 14:30:09 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongodb
PKG_SUPPORTED_OPTIONS=	ssl

# The prospect of using databases/wiredtiger is unclear yet;
# MongoDB doesn't provide guarantees for non-bundled WiredTiger:
# https://groups.google.com/forum/#!msg/mongodb-dev/31FQSo4KVCI/Fx-WtJ9fzU4J
.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "aarch64"
PKG_SUPPORTED_OPTIONS+=	wiredtiger
PKG_SUGGESTED_OPTIONS+=	wiredtiger
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
SCONS_ARGS+=		--ssl
.endif

.if !empty(PKG_OPTIONS:Mwiredtiger)
SCONS_ARGS+=		--wiredtiger=on
.else
SCONS_ARGS+=		--wiredtiger=off
.endif
