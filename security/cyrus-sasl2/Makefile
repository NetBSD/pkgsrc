# $NetBSD: Makefile,v 1.1.1.1 2002/10/27 15:09:00 chris Exp $

DISTNAME=		cyrus-sasl-2.1.9
SVR4_PKGNAME=		csasl
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
			ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/sasl/

MAINTAINER=		chris@netbsd.org
HOMEPAGE=		http://asg.web.cmu.edu/sasl/
COMMENT=		Simple Authentication and Security Layer

USE_BUILDLINK2=		YES
AUTOMAKE_REQD=		1.4
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

.include "../../mk/bsd.prefs.mk"

# CYRUS_USER		username of the Cyrus administrator
# CYRUS_GROUP		group of the Cyrus administrator
#
CYRUS_USER?=		cyrus
CYRUS_GROUP?=		mail
FILES_SUBST+=		CYRUS_USER=${CYRUS_USER}

HTMLDIR=		${PREFIX}/share/doc/html/cyrus-sasl
SASLSOCKETDIR=		/var/run/sasl
FILES_SUBST+=		SASLSOCKETDIR=${SASLSOCKETDIR}
PLIST_SUBST+=		SASLSOCKETDIR=${SASLSOCKETDIR}

BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP

PLIST_SRC=		${.CURDIR}/PLIST.common

CONFIGURE_ARGS+=	--with-saslauthd=${SASLSOCKETDIR}
CONFIGURE_ARGS+=	--with-dblib=ndbm
CONFIGURE_ARGS+=	--with-dbpath=${PKG_SYSCONFDIR}/sasldb
CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/sasl2
CONFIGURE_ARGS+=	--with-rc4=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_DIR}

# Authentication mechanisms
CONFIGURE_ARGS+=	--enable-anon		# ANONYMOUS
CONFIGURE_ARGS+=	--enable-cram		# CRAM-MD5
CONFIGURE_ARGS+=	--enable-digest		# DIGEST-MD5
CONFIGURE_ARGS+=	--disable-login		# --- no LOGIN
CONFIGURE_ARGS+=	--enable-plain		# PLAIN
CONFIGURE_ARGS+=	--disable-scram		# --- no SCRAM-MD5
CONFIGURE_ARGS+=	--disable-sia		# --- no SIA
CONFIGURE_ARGS+=	--disable-srp		# --- no SRP
CONFIGURE_ARGS+=	--disable-krb4		# --- no KERBEROS_V4
CONFIGURE_ARGS+=	--enable-otp		# OTP

.if defined(SASL_USE_GSSAPI) && ${SASL_USE_GSSAPI} == "YES"
CONFIGURE_ARGS+=	--enable-gssapi=/usr	# GSSAPI
PLIST_SRC+=		${.CURDIR}/PLIST.krb5
.else
CONFIGURE_ARGS+=	--disable-gssapi	# --- no GSSAPI
.endif

PLIST_SRC+=		${.CURDIR}/PLIST.plugins

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_DIR}
.else
CONFIGURE_ARGS+=	--without-pam
.endif

PKG_GROUPS=		${CYRUS_GROUP}
PKG_USERS=		${CYRUS_USER}:${CYRUS_GROUP}::::${SH}
RCD_SCRIPTS=		saslauthd
OWN_DIRS=		${PREFIX}/lib/sasl2

post-extract:
	${CP} ${FILESDIR}/sasl-config.in ${WRKSRC}/plugins

pre-configure:
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${AUTOMAKE} --gnu
	cd ${WRKSRC} && ${AUTOCONF}

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt ${HTMLDIR}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
