# $NetBSD: Makefile,v 1.46 2004/10/03 00:18:08 tv Exp $

.include "Makefile.common"

PKGREVISION=	7
SVR4_PKGNAME=	csasl
COMMENT=	Simple Authentication and Security Layer

# Authentication mechanisms
CONFIGURE_ARGS+=	--enable-anon		# ANONYMOUS
CONFIGURE_ARGS+=	--enable-cram		# CRAM-MD5
CONFIGURE_ARGS+=	--enable-plain		# PLAIN
CONFIGURE_ARGS+=	--enable-digest		# DIGEST-MD5
CONFIGURE_ARGS+=	--with-rc4=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"

.if defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS])     
PKG_DEFAULT_OPTIONS+=	gssapi
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
