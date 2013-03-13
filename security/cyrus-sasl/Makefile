# $NetBSD: Makefile,v 1.67 2013/03/13 03:31:40 obache Exp $

PKGREVISION=	2
SVR4_PKGNAME=	csasl
COMMENT=	Simple Authentication and Security Layer

.include "Makefile.common"

CPPFLAGS+=	-DPIC -fPIC

.include "options.mk"

BUILD_DEFS+=		VARBASE

# Support using Cyrus saslauthd (security/cyrus-saslauthd) for plaintext
# password authentication.
#
SASLSOCKETDIR?=		${VARBASE}/run/saslauthd
CONFIGURE_ARGS+=	--with-saslauthd=${SASLSOCKETDIR:Q}
BUILD_DEFS+=		SASLSOCKETDIR
# let not to build & install saslauthd here.
SUBST_CLASSES+=		saslauthd
SUBST_STAGE.saslauthd=	pre-configure
SUBST_FILES.saslauthd=	Makefile.in
SUBST_SED.saslauthd=	-e 's|@SASLAUTHD_TRUE@|\#|g'
SUBST_SED.saslauthd+=	-e 's|@SASLAUTHD_FALSE@||g'

# Support using the Courier authdaemond (security/courier-authlib) for
# plaintext password authentication.
#
AUTHDAEMONVAR?=		${VARBASE}/authdaemon
CONFIGURE_ARGS+=	--with-authdaemond=${AUTHDAEMONVAR}/socket
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

# Let not to build sample codes.
CONFIGURE_ARGS+=	--enable-sample=no

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail
FILES_SUBST+=		CYRUS_USER=${CYRUS_USER:Q}
FILES_SUBST+=		ROOT_USER=${ROOT_USER:Q}
PKG_GROUPS_VARS+=	CYRUS_GROUP
PKG_USERS_VARS+=	CYRUS_USER

PKG_GROUPS=		${CYRUS_GROUP}
PKG_USERS=		${CYRUS_USER}:${CYRUS_GROUP}
PKG_SHELL.${CYRUS_USER}=${SH}

MESSAGE_SUBST+=		PLUGINDIR=${PLUGINDIR:Q}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc; for file in *.fig *.html *.txt; do		\
		${INSTALL_DATA} $${file} ${DESTDIR}${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
