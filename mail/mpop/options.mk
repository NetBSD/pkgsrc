# $NetBSD: options.mk,v 1.4 2025/02/21 17:49:42 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mpop
PKG_SUPPORTED_OPTIONS=		gsasl idn scripts secret
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls ssl
PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-tls=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-tls=openssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tls
.endif

.if !empty(PKG_OPTIONS:Mgsasl)
CONFIGURE_ARGS+=	--with-libgsasl
BUILDLINK_API_DEPENDS.gsasl+=	gsasl>=2.1
.  include "../../security/gsasl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libgsasl
.endif

.if !empty(PKG_OPTIONS:Midn)
.  include "../../devel/libidn2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

.if !empty(PKG_OPTIONS:Msecret)
.  include "../../security/libsecret/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libsecret
.else
CONFIGURE_ARGS+=	--without-libsecret
.endif

.PHONY: install-mpop-scripts
PLIST_VARS+=		scripts
.if !empty(PKG_OPTIONS:Mscripts)
PLIST.scripts=		yes
USE_TOOLS+=		pax
INSTALLATION_DIRS+=	share/mpop
install-mpop-scripts:
	cd ${WRKSRC}/scripts && \
		pax -rw vim \
			${DESTDIR}${PREFIX}/share/mpop
.else
install-mpop-scripts:
.endif
