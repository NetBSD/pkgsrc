# $NetBSD: Makefile,v 1.17 2004/01/08 22:13:14 jlam Exp $

.include "Makefile.common"

PKGREVISION=	1
SVR4_PKGNAME=	csasl
COMMENT=	Simple Authentication and Security Layer

PLIST_SRC+=		${PKGDIR}/PLIST.common

# Authentication mechanisms
CONFIGURE_ARGS+=	--enable-anon		# ANONYMOUS
CONFIGURE_ARGS+=	--enable-plain		# PLAIN
CONFIGURE_ARGS+=	--enable-cram		# CRAM-MD5
CONFIGURE_ARGS+=	--enable-otp		# OTP

CONFIGURE_ARGS+=	--enable-digest		# DIGEST-MD5
CONFIGURE_ARGS+=	--with-rc4
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"

BUILD_DEFS+=		USE_PAM SASL_USE_GSSAPI

.if exists(/dev/urandom)
CONFIGURE_ARGS+=	--with-devrandom=/dev/urandom
.endif

# saslauthd needs to find libraries for different authentication mechanisms.
.if defined(USE_PAM)
.  include "../../security/PAM/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.pam}
.endif

.if defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-gssapi=/usr	# GSSAPI
PLIST_SRC+=		${PKGDIR}/PLIST.krb5
.  if exists(/usr/include/krb5/krb5.h)
CPPFLAGS+=		-I/usr/include/krb5
.  endif
LIBS+=-lcrypto
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.plugins

USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

PKG_GROUPS=		${CYRUS_GROUP}
PKG_USERS=		${CYRUS_USER}:${CYRUS_GROUP}::::${SH}
RCD_SCRIPTS=		saslauthd
OWN_DIRS=		${PLUGINDIR}

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
