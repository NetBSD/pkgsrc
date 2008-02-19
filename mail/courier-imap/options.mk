# $NetBSD: options.mk,v 1.1 2008/02/19 18:45:14 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.courier-imap
PKG_SUPPORTED_OPTIONS=		fam
PKG_OPTIONS_OPTIONAL_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		gnutls ssl
PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

###
### File Alteration Monitor support.  This allows multiple imapd or pop3d
### processes to be notified of changes to the underlying maildirs instead
### of needing to poll the maildirs.
###
.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
.endif

###
### Default to using the OpenSSL or GNUTLS tools for creating certificates.
###
.if !empty(PKG_OPTIONS:Mgnutls) || !empty(PKG_OPTIONS:Mssl)
SUBST_CLASSES+=		tls
SUBST_FILES.tls=	imap/mkimapdcert.in imap/mkpop3dcert.in
SUBST_STAGE.tls=	pre-configure
COURIER_CERTTOOL=	${PREFIX}/bin/certtool
COURIER_OPENSSL=	${PREFIX}/bin/openssl
.endif
.if !empty(PKG_OPTIONS:Mgnutls)
SUBST_SED.tls=		-e "s|@ssllib@|gnutls|g"
.endif
.if !empty(PKG_OPTIONS:Mssl)
USE_TOOLS+=		openssl:run
COURIER_OPENSSL=	${TOOLS_OPENSSL}
SUBST_SED.tls=		-e "s|@ssllib@|openssl|g"
.endif
