# $NetBSD: Makefile,v 1.44 2005/12/05 23:55:17 rillig Exp $

.include "Makefile.common"

PKGREVISION=	2
SVR4_PKGNAME=	csasl
COMMENT=	Simple Authentication and Security Layer

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

CONFIGURE_ARGS+=	--with-dblib=${SASL_DBTYPE:Q}
CONFIGURE_ARGS+=	--with-dbpath=${PKG_SYSCONFDIR}/sasldb

# Support using Cyrus saslauthd (security/cyrus-saslauthd) for plaintext
# password authentication.
#
SASLSOCKETDIR?=		${VARBASE}/run/saslauthd
CONFIGURE_ARGS+=	--with-saslauthd=${SASLSOCKETDIR:Q}
BUILD_DEFS+=		SASLSOCKETDIR

# Support using the Courier authdaemond (security/courier-authlib) for
# plaintext password authentication.
#
AUTHDAEMONVAR?=		${VARBASE}/authdaemon
CONFIGURE_ARGS+=        --with-authdaemond=${AUTHDAEMONVAR}/socket
BUILD_DEFS+=		AUTHDAEMONVAR

# Support using APOP against a POP server for plaintext password
# authentication.
#
CONFIGURE_ARGS+=	--enable-checkapop

.if exists(/dev/urandom)
SASL_ENTROPY_SOURCE?=	/dev/urandom
.endif
.if defined(SASL_ENTROPY_SOURCE)
CONFIGURE_ARGS+=	--with-devrandom=${SASL_ENTROPY_SOURCE:Q}
.endif
BUILD_DEFS+=		SASL_ENTROPY_SOURCE

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail
FILES_SUBST+=		CYRUS_USER=${CYRUS_USER:Q}
FILES_SUBST+=		ROOT_USER=${ROOT_USER:Q}
BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP

PKG_GROUPS=		${CYRUS_GROUP}
PKG_USERS=		${CYRUS_USER}:${CYRUS_GROUP}::::${SH}

MESSAGE_SUBST+=		_PLUGINDIR=${_PLUGINDIR}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc; for file in *.fig *.html *.txt; do		\
		${INSTALL_DATA} $$file ${DOCDIR};			\
	done

.include "../../mk/bsd.pkg.mk"
