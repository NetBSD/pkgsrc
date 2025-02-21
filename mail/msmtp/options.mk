# $NetBSD: options.mk,v 1.18 2025/02/21 17:50:05 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.msmtp
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

.PHONY: install-msmtp-scripts
PLIST_VARS+=		scripts
.if !empty(PKG_OPTIONS:Mscripts)
PLIST.scripts=		yes
USE_TOOLS+=		bash:run pax
INSTALLATION_DIRS+=	share/msmtp
REPLACE_BASH+=		scripts/find_alias/find_alias_for_msmtp.sh
REPLACE_BASH+=		scripts/msmtpq/msmtp-queue
REPLACE_SH+=		scripts/msmtpq/msmtpq
REPLACE_SH+=		scripts/msmtpqueue/msmtp-enqueue.sh
REPLACE_SH+=		scripts/msmtpqueue/msmtp-listqueue.sh
REPLACE_SH+=		scripts/msmtpqueue/msmtp-runqueue.sh
REPLACE_BASH+=		scripts/set_sendmail/set_sendmail.sh
install-msmtp-scripts:
	cd ${WRKSRC}/scripts && \
		pax -rw find_alias msmtpq msmtpqueue \
			set_sendmail vim \
			${DESTDIR}${PREFIX}/share/msmtp
.else
install-msmtp-scripts:
.endif
