# $NetBSD: options.mk,v 1.3 2007/12/27 23:41:42 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openssl
PKG_SUPPORTED_OPTIONS=	idea mdc2 rc5
.include "../../mk/bsd.options.mk"

OPENSSL_LICENSE=	# empty

###
### Support for the IDEA algorithm
###	US Patent: 5214703
###	Europe Patent: EP0482154
###	Japan Patent: 508119/1991
###
.if !empty(PKG_OPTIONS:Midea)
OPENSSL_LICENSE+=	idea-license
PLIST_SUBST+=		IDEA=
.else
CONFIGURE_ARGS+=	no-idea
PLIST_SUBST+=		IDEA="@comment "
.endif

###
### Support for the MDC2 algorithm
###	US Patent: 4908861
###
.if !empty(PKG_OPTIONS:Mmdc2)
# A license file is needed.
OPENSSL_LICENSE+=	mdc2-nonlicense
PLIST_SUBST+=		MDC2=
.else
CONFIGURE_ARGS+=	no-mdc2
PLIST_SUBST+=		MDC2="@comment "
.endif

###
### Support for the RC5 algorithm
###	US Patent: 5724428, 5835600, 6269163
###
.if !empty(PKG_OPTIONS:Mrc5)
# A license file is needed.
OPENSSL_LICENSE+=	rc5-nonlicense
PLIST_SUBST+=		RC5=
.else
CONFIGURE_ARGS+=	no-rc5
PLIST_SUBST+=		RC5="@comment "
.endif

.if !empty(OPENSSL_LICENSE)
# pkgsrc does not handle multiple licenses
LICENSE=	openssl-patented-algorithms-nonlicense
.endif
