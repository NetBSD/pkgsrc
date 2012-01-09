# $NetBSD: options.mk,v 1.12 2012/01/09 14:53:31 drochner Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.lftp

PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=	gnutls ssl

PKG_SUPPORTED_OPTIONS=	perl dnssec
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--without-openssl
USE_TOOLS+=	pkg-config
.  include "../../security/gnutls/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--without-openssl
.endif

.PHONY: post-install-perl

.if !empty(PKG_OPTIONS:Mperl)
USE_TOOLS+=		perl:run
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-String-CRC32-[0-9]*:../../textproc/p5-String-CRC32
REPLACE_PERL+=		src/convert-mozilla-cookies src/verify-file
PLIST_SRC+=		${PKGDIR}/PLIST.perl

post-install-perl:
	${INSTALL_SCRIPT} ${WRKSRC}/src/convert-mozilla-cookies \
		${WRKSRC}/src/verify-file ${DESTDIR}${PREFIX}/share/lftp
.else
post-install-perl:
.endif

###
### DNSSEC support
###
.if !empty(PKG_OPTIONS:Mdnssec)
. include "../../security/dnssec-tools/buildlink3.mk"
CONFIGURE_ARGS+=	--with-dnssec-local-validation
.endif
