# $NetBSD: Makefile,v 1.42 2004/03/23 06:13:30 jlam Exp $

.include "Makefile.common"

SVR4_PKGNAME=	csasl
PKGREVISION=	5
COMMENT=	Simple Authentication and Security Layer

PLIST_SRC+=		${.CURDIR}/PLIST.common

# Authentication mechanisms
CONFIGURE_ARGS+=	--enable-anon		# ANONYMOUS
CONFIGURE_ARGS+=	--enable-cram		# CRAM-MD5

CONFIGURE_ARGS+=	--enable-plain		# PLAIN
.if defined(USE_PAM)
.  include "../../security/PAM/buildlink3.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.pam}
.endif

CONFIGURE_ARGS+=	--enable-digest		# DIGEST-MD5
CONFIGURE_ARGS+=	--with-rc4=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"

.if defined(KERBEROS) || \
    (defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS]))
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}	# GSSAPI
PLIST_SRC+=		${.CURDIR}/PLIST.krb5
.endif

PLIST_SRC+=		${.CURDIR}/PLIST.plugins

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
