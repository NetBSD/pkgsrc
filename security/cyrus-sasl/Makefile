# $NetBSD: Makefile,v 1.44 2004/07/30 21:05:41 jlam Exp $

.include "Makefile.common"

PKGREVISION=	6
SVR4_PKGNAME=	csasl
COMMENT=	Simple Authentication and Security Layer

# Authentication mechanisms
CONFIGURE_ARGS+=	--enable-anon		# ANONYMOUS
CONFIGURE_ARGS+=	--enable-cram		# CRAM-MD5
CONFIGURE_ARGS+=	--enable-plain		# PLAIN
CONFIGURE_ARGS+=	--enable-digest		# DIGEST-MD5
CONFIGURE_ARGS+=	--with-rc4=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"

# Global and legacy options
.if defined(KERBEROS) || defined(USE_PAM) || defined(SASL_USE_GSSAPI)
.  if !defined(PKG_OPTIONS.cyrus-sasl)
.    if defined(KERBEROS)
PKG_OPTIONS.cyrus-sasl+=	kerberos
.    endif
.    if defined(USE_PAM) && !empty(USE_PAM:M[yY][eE][sS])     
PKG_OPTIONS.cyrus-sasl+=	PAM
.    endif
.    if defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS])     
PKG_OPTIONS.cyrus-sasl+=	gssapi
.    endif
.  endif
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.cyrus-sasl
PKG_SUPPORTED_OPTIONS=	PAM gssapi kerberos
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:MPAM)
.  include "../../security/PAM/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.pam}
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Mgssapi)
PKG_OPTIONS+=		gssapi
.  endif
.endif

.if !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}	# GSSAPI
PLIST_SUBST+=		GSSAPI=
.else
PLIST_SUBST+=		GSSAPI="@comment "
.endif

USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

PKG_GROUPS=		${CYRUS_GROUP}
PKG_USERS=		${CYRUS_USER}:${CYRUS_GROUP}::::${SH}
RCD_SCRIPTS=		sasl_pwcheck saslauthd
OWN_DIRS=		${PREFIX}/lib/sasl

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
