# $NetBSD: Makefile,v 1.6 2002/11/23 14:44:53 chris Exp $

DISTNAME=		cyrus-sasl-2.1.9
PKGREVISION=		2
SVR4_PKGNAME=		csasl
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
			ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/sasl/

MAINTAINER=		chris@netbsd.org
HOMEPAGE=		http://asg.web.cmu.edu/sasl/
COMMENT=		Simple Authentication and Security Layer

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
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
# /var/run/saslauthd matches the default value in configure.
SASLSOCKETDIR=		/var/run/saslauthd
FILES_SUBST+=		SASLSOCKETDIR=${SASLSOCKETDIR}
PLIST_SUBST+=		SASLSOCKETDIR=${SASLSOCKETDIR}

BUILD_DEFS+=		CYRUS_USER CYRUS_GROUP

PLIST_SRC=		${PKGDIR}/PLIST.common

CONFIGURE_ARGS+=	--with-saslauthd=${SASLSOCKETDIR}
CONFIGURE_ARGS+=	--with-dblib=ndbm
CONFIGURE_ARGS+=	--with-dbpath=${PKG_SYSCONFDIR}/sasldb
CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/sasl2
CONFIGURE_ARGS+=	--with-rc4
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

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

.if defined(SASL_USE_GSSAPI) && !empty(SASL_USE_GSSAPI:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-gssapi=/usr	# GSSAPI
PLIST_SRC+=		${PKGDIR}/PLIST.krb5
.  if exists(/usr/include/krb5/krb5-types.h)
CPPFLAGS+=	-I/usr/include/krb5
.  endif
.else
CONFIGURE_ARGS+=	--disable-gssapi	# --- no GSSAPI
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.plugins
PLIST_SRC+=		${PKGDIR}/PLIST.post

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink2.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.pam}
.else
CONFIGURE_ARGS+=	--without-pam
.endif

PKG_GROUPS=		${CYRUS_GROUP}
PKG_USERS=		${CYRUS_USER}:${CYRUS_GROUP}::::${SH}
RCD_SCRIPTS=		saslauthd
OWN_DIRS=		${PREFIX}/lib/sasl2

# clean up a bit to help package maintainer produce patch files
post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}			\
	${FIND} ${WRKSRC} -type f -name "*.orig" | ${XARGS} ${RM}

# Left here as reference for patch makers...
#pre-configure:
#	cd ${WRKSRC};					\
#	${ACLOCAL} -I cmulocal -I config;		\
#	${AUTOHEADER};					\
#	${AUTOMAKE} -a --gnu -i ;			\
#	${AUTOCONF}

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt ${HTMLDIR}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
