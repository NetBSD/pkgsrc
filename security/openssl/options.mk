# $NetBSD: options.mk,v 1.12 2020/01/20 17:42:53 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssl
PKG_SUPPORTED_OPTIONS=	idea md2 mdc2 rc5 zlib threads
PKG_SUGGESTED_OPTIONS=	idea md2 mdc2 rc5 threads

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

#
# Support optional algorithms
#
.for alg in idea md2 mdc2 rc5
.  if !empty(PKG_OPTIONS:M${alg})
CONFIGURE_ARGS+=	enable-${alg}
PLIST.${alg}=		yes
.  else
CONFIGURE_ARGS+=	no-${alg}
.  endif
.endfor
#
# Only supported in certain Linux configurations, needs proper handling if
# it is to be supported as an option.
#
CONFIGURE_ARGS+=	no-afalgeng

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	zlib
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	no-zlib
.endif

.if !empty(PKG_OPTIONS:Mthreads)
CONFIGURE_ARGS+=	threads
.else
CONFIGURE_ARGS+=	no-threads
.endif
