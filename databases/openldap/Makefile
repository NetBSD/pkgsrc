# $NetBSD: Makefile,v 1.43 2002/06/15 21:19:59 cjep Exp $

DISTNAME=	openldap-2.0.23
SVR4_PKGNAME=	oldap
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.OpenLDAP.org/
COMMENT=	Lightweight directory access protocol server and client package

CONFLICTS+=	ldapsdk-[0-9]*

USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK_SED+=	-e "s|-L${WRKSRC}/libraries||g"

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/build/ltconfig

# unfortunately, --enable-phonetic cannot be disabled by runtime configuration
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-dnssrv
CONFIGURE_ARGS+=	--enable-cldap
CONFIGURE_ARGS+=	--enable-passwd
CONFIGURE_ARGS+=	--enable-shell
CONFIGURE_ARGS+=	--enable-wrappers
CONFIGURE_ARGS+=	--with-tls=openssl
CONFIGURE_ARGS+=	--without-readline

# Apparently, only _native_ pthreads are good enough, since compiling
# OpenLDAP with a userland thread package like GNU pth results in a
# slapd that isn't capable of passing the regression tests.
#
USE_PTHREAD=		native

PKG_SYSCONFSUBDIR=	openldap
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--localstatedir=/var/openldap

.include "../../mk/bsd.prefs.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} != "none")
CONFIGURE_ARGS+=	--with-threads
PLIST_SRC=		${.CURDIR}/PLIST.slurpd ${.CURDIR}/PLIST
.endif

.if ${OPSYS} == "SunOS"
.include "../../databases/db/buildlink.mk"
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/db2
LIBS=		-ldb2 -lpthread -lrt
.endif

.if defined(USE_SASL) && (${USE_SASL} == "YES")
.include "../../security/cyrus-sasl/buildlink.mk"
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

CNFS=		ldap.conf ldapfilter.conf ldaptemplates.conf		\
		ldapsearchprefs.conf
CNFS_PERMS=	slapd.conf
SUPPS=		schema/corba.schema schema/core.schema			\
		schema/cosine.schema schema/inetorgperson.schema	\
		schema/java.schema schema/krb5-kdc.schema		\
		schema/misc.schema schema/nis.schema			\
		schema/openldap.schema

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

post-build:
	@for script in ${RCD_SCRIPTS}; do				\
		${SED} ${FILES_SUBST_SED} ${FILESDIR}/$${script}.sh	\
			> ${WRKDIR}/$${script};				\
	done

post-install:
	for script in ${RCD_SCRIPTS}; do				\
		${INSTALL_SCRIPT} ${WRKDIR}/$${script}			\
			${PREFIX}/etc/rc.d/$${script};			\
	done
	${INSTALL_DATA_DIR} ${EGDIR}/schema
	for file in ${CNFS} ${CNFS_PERMS} ${SUPPS}; do			\
		if [ ! -e ${PKG_SYSCONFDIR}/$${file}.default ]; then	\
			${CP} -p ${PKG_SYSCONFDIR}/$${file}		\
				${PKG_SYSCONFDIR}/$${file}.default;	\
		fi;							\
		${INSTALL_DATA} ${PKG_SYSCONFDIR}/$${file}.default	\
			${EGDIR}/$${file};				\
		${RM} -f ${PKG_SYSCONFDIR}/$${file}.default;		\
	done

.include "../../security/openssl/buildlink.mk"
.include "../../security/tcp_wrappers/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
