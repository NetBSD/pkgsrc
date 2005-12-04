# $NetBSD: options.mk,v 1.6 2005/12/04 22:12:07 salo Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.lftp

PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=	gnutls ssl

PKG_SUPPORTED_OPTIONS=	perl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--without-openssl
.  include "../../security/gnutls/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mperl)
USE_TOOLS+=		perl:run
DEPENDS+=		p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=		p5-String-CRC32-[0-9]*:../../textproc/p5-String-CRC32
REPLACE_PERL=		src/convert-netscape-cookies src/verify-file
PLIST_SRC+=		${PKGDIR}/PLIST.perl

post-install-perl:
	${INSTALL_SCRIPT} ${WRKSRC}/src/convert-netscape-cookies \
		${WRKSRC}/src/verify-file ${PREFIX}/share/lftp
.else
post-install-perl:
.endif
