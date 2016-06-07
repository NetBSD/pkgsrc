# $NetBSD: options.mk,v 1.15 2016/06/07 07:08:30 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.msmtp

PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls ssl

PKG_SUPPORTED_OPTIONS=	gsasl idn inet6 scripts secret
PKG_SUGGESTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=openssl
CONFIGURE_ARGS+=	--with-libssl-prefix=${BUILDLINK_PREFIX.openssl}
.elif !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=gnutls
CONFIGURE_ARGS+=	--with-libgnutls-prefix=${BUILDLINK_PREFIX.gnutls}
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

###
### GNUsasl support
###
.if !empty(PKG_OPTIONS:Mgsasl)
.  include "../../security/gsasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgsasl
CONFIGURE_ARGS+=	--with-libgsasl-prefix=${BUILDLINK_PREFIX.gsasl}
.else
CONFIGURE_ARGS+=	--without-libgsasl
.endif

###
### Internationalized Domain Names (IDN) support
###
.if !empty(PKG_OPTIONS:Midn)
.  include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn
CONFIGURE_ARGS+=	--with-libidn-prefix=${BUILDLINK_PREFIX.libidn}
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

###
### GNOME keyring support (via libsecret)
###
.if !empty(PKG_OPTIONS:Msecret)
.  include "../../security/libsecret/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libsecret
USE_TOOLS+=		pkg-config
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
