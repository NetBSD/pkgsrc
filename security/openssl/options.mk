# $NetBSD: options.mk,v 1.7 2011/11/02 22:51:07 jnemeth Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssl
PKG_SUPPORTED_OPTIONS=	idea mdc2 rc5 zlib threads
PKG_SUGGESTED_OPTIONS=	threads

.include "../../mk/bsd.options.mk"

OPENSSL_LICENSE=	# empty

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

###
### Support for the IDEA algorithm
###	US Patent: 5214703
###	Europe Patent: EP0482154
###	Japan Patent: 508119/1991
###
.if !empty(PKG_OPTIONS:Midea)
OPENSSL_LICENSE+=	idea-license
PLIST.idea=		yes
.else
CONFIGURE_ARGS+=	no-idea
.endif

###
### Support for the MDC2 algorithm
###	US Patent: 4908861
###
.if !empty(PKG_OPTIONS:Mmdc2)
# A license file is needed.
OPENSSL_LICENSE+=	mdc2-nonlicense
CONFIGURE_ARGS+=	enable-mdc2
PLIST.mdc2=		yes
.else
CONFIGURE_ARGS+=	no-mdc2
.endif

###
### Support for the RC5 algorithm
###	US Patent: 5724428, 5835600, 6269163
###
.if !empty(PKG_OPTIONS:Mrc5)
# A license file is needed.
OPENSSL_LICENSE+=	rc5-nonlicense
CONFIGURE_ARGS+=	enable-rc5
PLIST.rc5=		yes
.else
CONFIGURE_ARGS+=	no-rc5
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
