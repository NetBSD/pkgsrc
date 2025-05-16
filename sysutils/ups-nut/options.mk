# $NetBSD: options.mk,v 1.4 2025/05/16 16:55:21 martin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ups-nut
PKG_SUPPORTED_OPTIONS=		python
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		nss openssl
PKG_SUGGESTED_OPTIONS=		python openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnss)
CONFIGURE_ARGS+=	--with-ssl=nss --with-nss --without-openssl
.  include "../../devel/nss/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-ssl=openssl --without-nss --with-openssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if !empty(PKG_OPTIONS:Mpython)
# Force only our chosen python3 (see Makefile comment for --without-python2)
CONFIGURE_ARGS+=	--with-python3=${PYTHONBIN}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
PLIST.python=		yes
# \todo Move to split package.
.else
CONFIGURE_ARGS+=	--without-python3
.endif
