# $NetBSD: Makefile,v 1.28 2004/03/29 05:47:31 jlam Exp $

.include "Makefile.common"

SVR4_PKGNAME=	csasl
COMMENT=	Simple Authentication and Security Layer

PLIST_SRC+=		${PKGDIR}/PLIST.common

.if exists(/usr/include/ndbm.h)
SASL_DBTYPE?=		ndbm
.else
SASL_DBTYPE?=		berkeley
.endif
BUILD_DEFS+=		SASL_DBTYPE

.if ${SASL_DBTYPE} == "berkeley"
USE_DB185=		no
.  include "../../mk/bdb.buildlink3.mk"
.endif

CONFIGURE_ARGS+=	--with-dblib=${SASL_DBTYPE}
CONFIGURE_ARGS+=	--with-dbpath=${PKG_SYSCONFDIR}/sasldb

# Authentication mechanisms
CONFIGURE_ARGS+=	--enable-anon		# ANONYMOUS
CONFIGURE_ARGS+=	--enable-checkapop	# CHECKAPOP
CONFIGURE_ARGS+=	--enable-cram		# CRAM-MD5
CONFIGURE_ARGS+=	--enable-otp		# OTP
CONFIGURE_ARGS+=	--enable-plain		# PLAIN

CONFIGURE_ARGS+=	--enable-digest		# DIGEST-MD5
CONFIGURE_ARGS+=	--with-rc4
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}
.include "../../security/openssl/buildlink3.mk"

# Support using the Courier authdaemon (mail/courier-auth*) for
# plaintext password authentication.
#
AUTHDAEMONVAR?=		/var/authdaemon
CONFIGURE_ARGS+=        --with-authdaemond=${AUTHDAEMONVAR}
BUILD_DEFS+=		AUTHDAEMONVAR

.if exists(/dev/urandom)
SASL_ENTROPY_SOURCE?=	/dev/urandom
.endif
.if defined(SASL_ENTROPY_SOURCE)
CONFIGURE_ARGS+=	--with-devrandom=${SASL_ENTROPY_SOURCE}
.endif
BUILD_DEFS+=		SASL_ENTROPY_SOURCE

.if defined(KERBEROS)
SASL_USE_GSSAPI=	yes
.endif
.if (defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS]))
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}	# GSSAPI
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
PLIST_SRC+=		${PKGDIR}/PLIST.krb5
.endif
BUILD_DEFS+=		SASL_USE_GSSAPI

PLIST_SRC+=		${PKGDIR}/PLIST.plugins

USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

PKG_GROUPS=		${CYRUS_GROUP}
PKG_USERS=		${CYRUS_USER}:${CYRUS_GROUP}::::${SH}
OWN_DIRS=		${PLUGINDIR}

MESSAGE_SUBST+=		_PLUGINDIR=${_PLUGINDIR}

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; for file in *.fig *.html *.txt; do		\
		${INSTALL_DATA} $$file ${HTMLDIR};			\
	done

.include "../../mk/bsd.pkg.mk"
