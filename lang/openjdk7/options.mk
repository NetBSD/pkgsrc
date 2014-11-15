# $NetBSD: options.mk,v 1.6 2014/11/15 12:10:54 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openjdk7
PKG_SUPPORTED_OPTIONS=		jre-jce # jdk-zero-vm
PKG_SUGGESTED_OPTIONS=		jre-jce

.include "../../mk/bsd.options.mk"

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Mjre-jce)
MAKE_ENV+=	UNLIMITED_CRYPTO=true
.endif

# this option builds a JVM without assembly optimisation. Useful for porting.
# NOTE: This is work in progress.
.if !empty(PKG_OPTIONS:Mjdk-zero-vm)
MAKE_ENV+=	ZERO_BUILD=true
.include "../../devel/libffi/buildlink3.mk"
.endif
