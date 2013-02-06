# $NetBSD: options.mk,v 1.9 2013/02/06 21:40:33 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssl
PKG_SUPPORTED_OPTIONS=	idea md2 mdc2 rc5 zlib threads
PKG_SUGGESTED_OPTIONS=	md2 threads

.include "../../mk/bsd.options.mk"

OPENSSL_LICENSE=	# empty

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

# A license file is needed.
# US Patent: 5724428, 5835600, 6269163
.if !empty(PKG_OPTIONS:Mrc5)
OPENSSL_LICENSE+=	rc5-nonlicense
.endif

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

.if !empty(OPENSSL_LICENSE)
# pkgsrc does not handle multiple licenses
LICENSE=	openssl-patented-algorithms-nonlicense
.endif
