# $NetBSD: Makefile,v 1.18 2004/01/09 19:37:48 jlam Exp $

.include "Makefile.common"

PKGREVISION=	2
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

BUILD_DEFS+=		SASL_USE_GSSAPI

.if exists(/dev/urandom)
CONFIGURE_ARGS+=	--with-devrandom=/dev/urandom
.endif

.if defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-gssapi=/usr	# GSSAPI
PLIST_SRC+=		${PKGDIR}/PLIST.krb5
.  if exists(/usr/include/krb5/krb5.h)
CPPFLAGS+=		-I/usr/include/krb5
.  endif
LIBS+=			-lcrypto
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.plugins

USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

PKG_GROUPS=		${CYRUS_GROUP}
PKG_USERS=		${CYRUS_USER}:${CYRUS_GROUP}::::${SH}
RCD_SCRIPTS=		saslauthd
OWN_DIRS=		${PLUGINDIR}

MESSAGE_SUBST+=		_PLUGINDIR=${_PLUGINDIR}

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
