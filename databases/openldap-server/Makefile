# $NetBSD: Makefile,v 1.4.2.1 2006/11/29 14:53:49 salo Exp $

PKGNAME=		${DISTNAME:S/-/-server-/}
PKGREVISION=		1
COMMENT=		Lightweight Directory Access Protocol server suite

CONFLICTS+=		openldap<2.3.23nb1

DEPENDS+=		openldap-client>=2.3.27nb1:../../databases/openldap-client

# slapd options
CONFIGURE_ARGS+=	--enable-slapd
CONFIGURE_ARGS+=	--enable-crypt
CONFIGURE_ARGS+=	--enable-wrappers

# slapd backends
CONFIGURE_ARGS+=	--enable-dnssrv
CONFIGURE_ARGS+=	--enable-ldap
CONFIGURE_ARGS+=	--enable-ldbm
CONFIGURE_ARGS+=	--enable-meta
CONFIGURE_ARGS+=	--enable-monitor
CONFIGURE_ARGS+=	--enable-null
CONFIGURE_ARGS+=	--enable-passwd
CONFIGURE_ARGS+=	--enable-shell

# slapd (stackable) overlays
CONFIGURE_ARGS+=	--enable-overlays

# slurpd options
CONFIGURE_ARGS+=	--enable-slurpd

BUILD_DIRS=		include libraries servers
TEST_DIRS=		tests
INSTALL_DIRS=		servers

BUILD_DEFS+=		SLAPD_USER SLURPD_USER LDAP_GROUP
BUILD_DEFS+=		OPENLDAP_ETCDIR OPENLDAP_VARDIR

PKG_GROUPS=		${LDAP_GROUP}
PKG_USERS=		${SLAPD_USER}:${LDAP_GROUP} ${SLURPD_USER}:${LDAP_GROUP}

OPENLDAP_FILEPERMS=	${ROOT_USER} ${LDAP_GROUP} 0640
SLAPD_DIRPERMS=		${SLAPD_USER} ${LDAP_GROUP} 0700
SLURPD_DIRPERMS=	${SLURPD_USER} ${LDAP_GROUP} 0770
RUN_DIRPERMS=		${ROOT_USER} ${LDAP_GROUP} 0775

MAKE_DIRS=		${OPENLDAP_ETCDIR}/schema
OWN_DIRS+=		${OPENLDAP_VARDIR}
OWN_DIRS_PERMS=		${OPENLDAP_VARDIR}/openldap-data ${SLAPD_DIRPERMS}
OWN_DIRS_PERMS+=	${OPENLDAP_VARDIR}/openldap-slurp ${SLURPD_DIRPERMS}
OWN_DIRS_PERMS+=	${OPENLDAP_VARDIR}/run ${RUN_DIRPERMS}

CNFS=			${CNFS_SCHEMAS_cmd:sh}
CNFS_SCHEMAS_cmd=	${SED} -ne "/\.ldif$$/p;/\.schema$$/p" ${PKGDIR}/PLIST | ${SED} -e "s|share/examples/openldap/||"

CNFS_PERMS=		slapd.conf

DB_CONFIG=		DB_CONFIG

RCD_SCRIPTS=		slapd slurpd

FILES_SUBST+=		OPENLDAP_ETCDIR=${OPENLDAP_ETCDIR:Q}
FILES_SUBST+=		SLAPD_USER=${SLAPD_USER}
FILES_SUBST+=		SLURPD_USER=${SLURPD_USER}

MESSAGE_SUBST+=		SLAPD_USER=${SLAPD_USER:Q}
MESSAGE_SUBST+=		SLURPD_USER=${SLURPD_USER:Q}
MESSAGE_SUBST+=		LDAP_GROUP=${LDAP_GROUP:Q}
MESSAGE_SUBST+=		OPENLDAP_VARDIR=${OPENLDAP_VARDIR:Q}
MESSAGE_SUBST+=		OPENLDAP_ETCDIR=${OPENLDAP_ETCDIR:Q}
MESSAGE_SUBST+=		CHOWN=${CHOWN}
MESSAGE_SUBST+=		CHMOD=${CHMOD}

.include "options.mk"

.include "../../databases/openldap/Makefile.common"

CONF_FILES_PERMS+=	${EGDIR}/DB_CONFIG ${OPENLDAP_VARDIR}/openldap-data/DB_CONFIG ${OPENLDAP_FILEPERMS}

.include "../../mk/bsd.pkg.mk"
