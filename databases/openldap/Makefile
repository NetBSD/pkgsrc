# $NetBSD: Makefile,v 1.75 2004/03/31 03:52:46 xtraeme Exp $

DISTNAME=		openldap-2.1.29
SVR4_PKGNAME=		oldap
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.OpenLDAP.org/
COMMENT=		Lightweight directory access protocol server and client package

CONFLICTS+=		ldapsdk-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
TEST_TARGET=		test

USE_DB185=		YES

PKG_SYSCONFSUBDIR=	openldap

# Unfortunately, --enable-phonetic cannot be disabled by runtime
# configuration.
#
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=/var/openldap
CONFIGURE_ARGS+=	--enable-dynamic   # link servers against shared libs
CONFIGURE_ARGS+=	--enable-bdb
CONFIGURE_ARGS+=	--enable-crypt
CONFIGURE_ARGS+=	--enable-dnssrv
CONFIGURE_ARGS+=	--enable-ldap
CONFIGURE_ARGS+=	--enable-ldbm
CONFIGURE_ARGS+=	--enable-passwd
CONFIGURE_ARGS+=	--enable-wrappers
CONFIGURE_ARGS+=	--with-tls=openssl
CONFIGURE_ARGS+=	--without-readline

BUILD_DEFS+=		USE_SASL USE_SASL2

.include "../../mk/bsd.prefs.mk"

.if defined(USE_SASL2) && (${USE_SASL2} == "YES")
.  include "../../security/cyrus-sasl2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cyrus-sasl
CONFIGURE_ARGS+=	--enable-spasswd
.elif defined(USE_SASL) && (${USE_SASL} == "YES")
.  include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-cyrus-sasl
CONFIGURE_ARGS+=	--enable-spasswd
.endif

.if defined(KERBEROS)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ENV+=		ol_with_kerberos=yes
CONFIGURE_ENV+=		ol_enable_kpasswd=yes
CONFIGURE_ARGS+=	--with-kerberos
CONFIGURE_ARGS+=	--enable-kpasswd
.else
CONFIGURE_ARGS+=	--without-kerberos
.endif

EGDIR=			${PREFIX}/share/examples/openldap
MAKE_DIRS=		${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/schema
OWN_DIRS=		/var/openldap
OWN_DIRS_PERMS=		/var/openldap/openldap-data ${ROOT_USER} ${ROOT_GROUP} 0700
OWN_DIRS_PERMS=		/var/openldap/openldap-ldbm ${ROOT_USER} ${ROOT_GROUP} 0700
OWN_DIRS_PERMS+=	/var/openldap/openldap-slurp ${ROOT_USER} ${ROOT_GROUP} 0700

CNFS=			ldap.conf
CNFS_PERMS=		slapd.conf
SUPPS=			schema/corba.schema schema/core.schema		\
			schema/java.schema schema/inetorgperson.schema	\
			schema/cosine.schema schema/misc.schema		\
			schema/nis.schema schema/openldap.schema

CONF_FILES=		# empty
CONF_FILES_PERMS=	# empty
SUPPORT_FILES=		# empty
.for FILE in ${CNFS}
CONF_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
.for FILE in ${CNFS_PERMS}
CONF_FILES_PERMS+=	${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}	\
			${ROOT_USER} ${ROOT_GROUP} 0600
.endfor
.for FILE in ${SUPPS}
SUPPORT_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor
RCD_SCRIPTS=		slapd

# On some platforms, while the package does build correctly using GNU pth,
# slapd isn't able to pass "make test".  One those platforms, don't build
# openldap with threads support unless we're using the native thread
# library.
#
OPENLDAP_PTH_BROKEN_PLATFORMS?=	# empty
.for _pattern_ in ${OPENLDAP_PTH_BROKEN_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${_pattern_})
OPENLDAP_PTHREAD_OPTS?=	native
.  endif
.endfor
OPENLDAP_PTHREAD_OPTS?=	require
PTHREAD_OPTS+=		${OPENLDAP_PTHREAD_OPTS}

.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--with-threads
PLIST_SUBST+=		SLURPD_COMMENT=
RCD_SCRIPTS+=		slurpd
.elif ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-threads=pth
PLIST_SUBST+=		SLURPD_COMMENT=
RCD_SCRIPTS+=		slurpd
.else
CONFIGURE_ARGS+=	--without-threads
PLIST_SUBST+=		SLURPD_COMMENT="@comment "
.endif

post-install:
	${_ULIMIT_CMD}cd ${WRKSRC}/libraries/libldap;			\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} install-conf sysconfdir=${EGDIR}
	${_ULIMIT_CMD}cd ${WRKSRC}/servers/slapd;			\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} install-conf sysconfdir=${EGDIR}; \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} install-schema sysconfdir=${EGDIR}

.include "../../mk/bsd.pkg.mk"
