# $NetBSD: options.mk,v 1.16 2018/09/19 09:26:45 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.msmtp

PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls ssl

PKG_SUPPORTED_OPTIONS=	gsasl idn scripts secret
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=openssl
.elif !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls=gnutls
.else
CONFIGURE_ARGS+=	--with-tls=no
.endif

###
### GNUsasl support
###
.if !empty(PKG_OPTIONS:Mgsasl)
.  include "../../security/gsasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgsasl
.else
CONFIGURE_ARGS+=	--without-libgsasl
.endif

###
### Internationalized Domain Names (IDN) support
###
.if !empty(PKG_OPTIONS:Midn)
.  include "../../devel/libidn2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

###
### GNOME keyring support (via libsecret)
###
.if !empty(PKG_OPTIONS:Msecret)
.  include "../../security/libsecret/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libsecret
.else
CONFIGURE_ARGS+=	--without-libsecret
.endif

###
### Install additional scripts
###
.if !empty(PKG_OPTIONS:Mscripts)
CHECK_INTERPRETER_SKIP+=	share/msmtp/find_alias/find_alias_for_msmtp.sh \
				share/msmtp/msmtpq/msmtp-queue \
				share/msmtp/msmtpq/msmtpq \
				share/msmtp/msmtpqueue/msmtp-enqueue.sh \
				share/msmtp/msmtpqueue/msmtp-listqueue.sh \
				share/msmtp/msmtpqueue/msmtp-runqueue.sh \
				share/msmtp/set_sendmail/set_sendmail.sh
PLIST.scripts=		yes
USE_TOOLS+=		pax
INSTALLATION_DIRS+=	share/msmtp
install-msmtp-scripts:
	cd ${WRKSRC}/scripts && \
		pax -rw find_alias msmtpq msmtpqueue \
			set_sendmail vim \
			${DESTDIR}${PREFIX}/share/msmtp
.else
install-msmtp-scripts:
.endif
