# $NetBSD: options.mk,v 1.1 2021/01/15 19:50:25 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bincimap
PKG_SUPPORTED_OPTIONS+=		inet6 pam tls
PKG_SUGGESTED_OPTIONS+=		inet6 tls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=			ucspi-tcp6>=1.10.7nb1:../../net/ucspi-tcp6
.else
DEPENDS+=			{ucspi-tcp6>=1.10.7nb1,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp
.endif

.if !empty(PKG_OPTIONS:Mpam)
DEPENDS+=			checkpassword-pam>=0.99nb1:../../sysutils/checkpassword-pam
.else
DEPENDS+=			checkpassword>=0.90nb1:../../sysutils/checkpassword
.endif

.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/io-ssl.cc doc/bincimap-faq.html \
			doc/manual/bincimap-manual.ps conf/bincimap.conf.in
SUBST_SED.paths=	-e 's|/usr/share/ssl/certs|${SSLDIR}/certs|g'
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
