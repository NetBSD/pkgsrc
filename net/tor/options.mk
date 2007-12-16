# $NetBSD: options.mk,v 1.2 2007/12/16 21:51:54 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tor
PKG_SUPPORTED_OPTIONS=	threads

.if !empty(PTHREAD_TYPE:Mnative)
PKG_SUGGESTED_OPTIONS+=	threads
.endif
.include "../../mk/bsd.options.mk"


###
### This enables new code for threaded operation on NetBSD, OpenBSD, etc.
### I used {PTHREAD,RESOLV}_AUTO_VARS here for consistency's sake, as
### I don't trust configure scripts to do this properly on all platforms.
###
.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	--enable-eventdns
CONFIGURE_ARGS+=	--enable-threads
PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
USE_FEATURES.openssl+=	threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
