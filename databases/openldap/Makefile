# $NetBSD: Makefile,v 1.57 2003/09/18 05:37:15 markd Exp $

DISTNAME=	openldap-2.1.22
SVR4_PKGNAME=	oldap
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.OpenLDAP.org/
COMMENT=	Lightweight directory access protocol server and client package

CONFLICTS+=	ldapsdk-[0-9]*

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
TEST_TARGET=		test

# unfortunately, --enable-phonetic cannot be disabled by runtime configuration
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-dnssrv
CONFIGURE_ARGS+=	--enable-ldap
CONFIGURE_ARGS+=	--enable-passwd
CONFIGURE_ARGS+=	--enable-wrappers
CONFIGURE_ARGS+=	--with-tls=openssl
CONFIGURE_ARGS+=	--without-readline
CONFIGURE_ARGS+=	--enable-ldbm
CONFIGURE_ARGS+=	--enable-crypt

PKG_SYSCONFSUBDIR=	openldap
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--localstatedir=/var/openldap
CPPFLAGS+=		-I${BUILDLINK_PREFIX.db4}/include/db4

BUILD_DEFS+=		USE_SASL USE_SASL2

.include "../../mk/bsd.prefs.mk"

.if defined(USE_SASL2) && (${USE_SASL2} == "YES")
.include "../../security/cyrus-sasl2/buildlink2.mk"
CONFIGURE_ARGS+=	--with-cyrus-sasl
CONFIGURE_ARGS+=	--enable-spasswd
.elif defined(USE_SASL) && (${USE_SASL} == "YES")
.include "../../security/cyrus-sasl/buildlink2.mk"
CONFIGURE_ARGS+=	--with-cyrus-sasl
CONFIGURE_ARGS+=	--enable-spasswd
.endif

.if defined(KERBEROS)
PKG_USE_KERBEROS=	YES
CONFIGURE_ARGS+=	--with-kerberos
.else
CONFIGURE_ARGS+=	--without-kerberos
.endif

EGDIR=		${PREFIX}/share/examples/openldap
MAKE_DIRS=	${PKG_SYSCONFDIR} ${PKG_SYSCONFDIR}/schema
OWN_DIRS=	/var/openldap
OWN_DIRS_PERMS=	/var/openldap/openldap-ldbm ${ROOT_USER} ${ROOT_GROUP} 0700
OWN_DIRS_PERMS+=/var/openldap/openldap-slurp ${ROOT_USER} ${ROOT_GROUP} 0700

CNFS=		ldap.conf
CNFS_PERMS=	slapd.conf
SUPPS=		schema/corba.schema schema/core.schema			\
		schema/cosine.schema schema/inetorgperson.schema	\
		schema/java.schema schema/misc.schema			\
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

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}/schema
	for file in ${CNFS} ${CNFS_PERMS} ${SUPPS}; do			\
		if [ ! -r ${PKG_SYSCONFDIR}/$${file}.default ]; then	\
			${CP} -p ${PKG_SYSCONFDIR}/$${file}		\
				${PKG_SYSCONFDIR}/$${file}.default;	\
		fi;							\
		${INSTALL_DATA} ${PKG_SYSCONFDIR}/$${file}.default	\
			${EGDIR}/$${file};				\
		${RM} -f ${PKG_SYSCONFDIR}/$${file}.default;		\
	done

.include "../../databases/db4/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
CONFIGURE_ARGS+=	--with-threads
PLIST_SRC=		${.CURDIR}/PLIST.slurpd ${.CURDIR}/PLIST
.else
#--without-threads is recommended with back-shell
CONFIGURE_ARGS+=	--without-threads --enable-shell
.endif

.include "../../mk/bsd.pkg.mk"
