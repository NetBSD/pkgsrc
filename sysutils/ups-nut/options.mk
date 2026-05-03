# $NetBSD: options.mk,v 1.5 2026/05/03 16:39:13 gdt Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ups-nut
PKG_SUPPORTED_OPTIONS=		python
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		nss openssl
PKG_SUGGESTED_OPTIONS=		python openssl

.include "../../mk/bsd.options.mk"

## NSS

.if !empty(PKG_OPTIONS:Mnss)
CONFIGURE_ARGS+=	--with-ssl=nss --with-nss --without-openssl
.  include "../../devel/nss/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-ssl=openssl --without-nss --with-openssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

## PYTHON

PLIST_VARS+=		python
.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--with-python3=${PYTHONBIN}
PLIST.python=		yes
# While this could be moved to a split package, so far nobody has said
# they would like that.
.else
CONFIGURE_ARGS+=	--without-python3
.endif
