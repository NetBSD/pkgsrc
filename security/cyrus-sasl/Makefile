# $NetBSD: Makefile,v 1.41 2003/11/12 03:39:42 jschauma Exp $

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
.  include "../../security/PAM/buildlink2.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.pam}
.endif

CONFIGURE_ARGS+=	--enable-digest		# DIGEST-MD5
CONFIGURE_ARGS+=	--with-rc4=${SSLBASE}
.include "../../security/openssl/buildlink2.mk"

.if defined(SASL_USE_GSSAPI) && ${SASL_USE_GSSAPI} == "YES"
CONFIGURE_ARGS+=	--enable-gssapi=/usr	# GSSAPI
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
