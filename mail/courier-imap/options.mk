# $NetBSD: options.mk,v 1.2 2008/02/21 15:50:29 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.courier-imap
PKG_SUPPORTED_OPTIONS=		courier-gnutls fam
PKG_SUGGESTED_OPTIONS=		# empty

.include "../../mk/bsd.options.mk"

###
### Support using the GNU TLS tools for creating certificates; otherwise
### default to using OpenSSL.
###
SUBST_CLASSES+=		tls
SUBST_FILES.tls=	imap/mkimapdcert.in imap/mkpop3dcert.in
SUBST_STAGE.tls=	pre-configure
COURIER_CERTTOOL=	${PREFIX}/bin/certtool
COURIER_OPENSSL=	${PREFIX}/bin/openssl

.if !empty(PKG_OPTIONS:Mcourier-gnutls)
SUBST_SED.tls=		-e "s|@ssllib@|gnutls|g"
.else
USE_TOOLS+=		openssl:run
COURIER_OPENSSL=	${TOOLS_OPENSSL}
SUBST_SED.tls=		-e "s|@ssllib@|openssl|g"
.endif

###
### File Alteration Monitor support.  This allows multiple imapd or pop3d
### processes to be notified of changes to the underlying maildirs instead
### of needing to poll the maildirs.
###
.if !empty(PKG_OPTIONS:Mfam)
.  include "../../mk/fam.buildlink3.mk"
.endif
