# $NetBSD: Makefile,v 1.32 2002/09/07 07:37:37 jlam Exp $

DISTNAME=		cyrus-sasl-1.5.27
SVR4_PKGNAME=		csasl
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
			ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/OLD-VERSIONS/sasl/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://asg.web.cmu.edu/sasl/
COMMENT=		Simple Authentication and Security Layer

USE_BUILDLINK2=		YES
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

CONFIGURE_ARGS+=	--with-pwcheck=${SASLSOCKETDIR}
CONFIGURE_ARGS+=	--with-saslauthd=${SASLSOCKETDIR}
CONFIGURE_ARGS+=	--with-dblib=ndbm
CONFIGURE_ARGS+=	--with-dbpath=${PKG_SYSCONFDIR}/sasldb
CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/sasl
CONFIGURE_ARGS+=	--with-rc4=${BUILDLINK_PREFIX.openssl}

# Authentication mechanisms
CONFIGURE_ARGS+=	--enable-anon		# ANONYMOUS
CONFIGURE_ARGS+=	--enable-cram		# CRAM-MD5
CONFIGURE_ARGS+=	--enable-digest		# DIGEST-MD5
CONFIGURE_ARGS+=	--disable-login		# --- no LOGIN
CONFIGURE_ARGS+=	--enable-plain		# PLAIN
CONFIGURE_ARGS+=	--disable-scram		# --- no SCRAM-MD5
CONFIGURE_ARGS+=	--disable-sia		# --- no SIA
CONFIGURE_ARGS+=	--disable-srp		# --- no SRP
CONFIGURE_ARGS+=	--disable-x509		# --- no X.509
CONFIGURE_ARGS+=	--disable-krb4		# --- no KERBEROS_V4

.if defined(SASL_USE_GSSAPI) && ${SASL_USE_GSSAPI} == "YES"
CONFIGURE_ARGS+=	--enable-gssapi=/usr	# GSSAPI
PLIST_SRC+=		${.CURDIR}/PLIST.krb5
.else
CONFIGURE_ARGS+=	--disable-gssapi	# --- no GSSAPI
.endif

PLIST_SRC+=		${.CURDIR}/PLIST.plugins

.if defined(USE_PAM)
.  include "../../security/PAM/buildlink2.mk"
BUILD_DEFS+=		USE_PAM
CONFIGURE_ARGS+=	--with-pam=${BUILDLINK_PREFIX.pam}
.else
CONFIGURE_ARGS+=	--without-pam
.endif

PKG_GROUPS=		${CYRUS_GROUP}
PKG_USERS=		${CYRUS_USER}:${CYRUS_GROUP}::::${SH}
RCD_SCRIPTS=		sasl_pwcheck saslauthd
OWN_DIRS=		${PREFIX}/lib/sasl

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

post-extract:
	cd ${WRKSRC}; ${RM} -f include/md5.h
	${CP} ${FILESDIR}/sasl-config.in ${WRKSRC}/plugins

pre-install:
	@for script in ${RCD_SCRIPTS}; do				\
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${script}.sh	\
			> ${WRKDIR}/$${script};				\
	done

post-install:
	for script in ${RCD_SCRIPTS}; do				\
		${INSTALL_SCRIPT} ${WRKDIR}/$${script}			\
			${PREFIX}/etc/rc.d/$${script};			\
	done
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt ${HTMLDIR}

.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
