# $NetBSD: options.mk,v 1.1 2010/12/23 12:36:01 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spidermonkey
PKG_SUPPORTED_OPTIONS=	threads unicode
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.options.mk"

###
### Threads support
###
.if !empty(PKG_OPTIONS:Mthreads)
PTHREAD_AUTO_VARS=	yes
CFLAGS+=		-DJS_THREADSAFE
.include "../../devel/nspr/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif

###
### UTF8 string support
###
.if !empty(PKG_OPTIONS:Municode)
CFLAGS+=		-DJS_C_STRINGS_ARE_UTF8
.endif
