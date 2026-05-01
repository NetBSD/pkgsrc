# $NetBSD: options.mk,v 1.1 2026/05/01 19:43:30 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libnfs
PKG_SUPPORTED_OPTIONS=	gnutls gssapi threads
PKG_SUGGESTED_OPTIONS=	# empty

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no

.if ${USE_BUILTIN.pthread:tl} == yes
PKG_SUGGESTED_OPTIONS+=	threads
.endif

# Requires Linux kTLS
.if exists(/usr/include/linux/tls.h)
PKG_SUGGESTED_OPTIONS+=	gnutls
.endif

.include "../../mk/bsd.options.mk"

###
### KRB5 support
###
.if !empty(PKG_OPTIONS:Mgssapi)
KRB5_ACCEPTED=		mit-krb5
CMAKE_CONFIGURE_ARGS+=  -DENABLE_GSSAPI=ON
.  include "../../mk/krb5.buildlink3.mk"
.else
CONFIGURE_ARGS+=	-DENABLE_GSSAPI=OFF
.endif

##
## Multithreading support
##
.if !empty(PKG_OPTIONS:Mthreads)
.  include "../../mk/pthread.buildlink3.mk"
# otherwise we get undefined refderences to semaphores
PTHREAD_AUTO_VARS=      yes
PTHREAD_OPTS+=          require
CMAKE_CONFIGURE_ARGS+=  -DENABLE_MULTITHREADING=ON
.else
CMAKE_CONFIGURE_ARGS+=  -DENABLE_MULTITHREADING=OFF
.endif

###
### GnuTLS support
###
.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
.endif
