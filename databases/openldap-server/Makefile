# $NetBSD: Makefile,v 1.73 2024/01/31 18:17:22 adam Exp $

PKGNAME=	${DISTNAME:S/-/-server-/}
COMMENT=	Lightweight Directory Access Protocol server suite

CONFLICTS+=	openldap<2.3.23nb1

DEPENDS+=	openldap-client>=2.3.27nb1:../../databases/openldap-client

# "error: 'for' loop initial declarations are only allowed in C99 mode"
# strict ISO C mode unsuitable for illumos, sigset_t...
FORCE_C_STD=	gnu99

CFLAGS.FreeBSD+=	-DMDB_DSYNC=O_SYNC
CFLAGS.DragonFly+=	-DMDB_DSYNC=O_SYNC -DMDB_FDATASYNC=fsync
CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS	# sigwait

# slapd options
CONFIGURE_ARGS+=	--enable-slapd
CONFIGURE_ARGS+=	--enable-crypt

# slapd backends
CONFIGURE_ARGS+=	--enable-dnssrv
CONFIGURE_ARGS+=	--enable-ldap
CONFIGURE_ARGS+=	--enable-meta
CONFIGURE_ARGS+=	--enable-monitor
CONFIGURE_ARGS+=	--enable-null
CONFIGURE_ARGS+=	--enable-passwd
CONFIGURE_ARGS+=	--enable-sock

# slapd (stackable) overlays
CONFIGURE_ARGS+=	--enable-overlays

BUILD_DIRS=		include libraries servers
TEST_DIRS=		tests
INSTALL_DIRS=		servers

BUILD_DEFS+=		OPENLDAP_ETCDIR OPENLDAP_VARDIR

PKG_GROUPS=		${LDAP_GROUP}
PKG_USERS=		${SLAPD_USER}:${LDAP_GROUP}

OPENLDAP_FILEPERMS=	${REAL_ROOT_USER} ${LDAP_GROUP} 0640
SLAPD_DIRPERMS=		${SLAPD_USER} ${LDAP_GROUP} 0700
RUN_DIRPERMS=		${REAL_ROOT_USER} ${LDAP_GROUP} 0775

MAKE_DIRS=		${OPENLDAP_ETCDIR}/schema
OWN_DIRS+=		${OPENLDAP_VARDIR}
OWN_DIRS_PERMS=		${OPENLDAP_VARDIR}/openldap-data ${SLAPD_DIRPERMS}
OWN_DIRS_PERMS+=	${OPENLDAP_VARDIR}/run ${RUN_DIRPERMS}

CNFS=			${CNFS_SCHEMAS_cmd:sh}
CNFS_SCHEMAS_cmd=	${SED} -ne "/\.ldif$$/p;/\.schema$$/p" ${PKGDIR}/PLIST | ${SED} -e "s|share/examples/openldap/||"

CNFS_PERMS=		slapd.conf

RCD_SCRIPTS=		slapd

FILES_SUBST+=		OPENLDAP_ETCDIR=${OPENLDAP_ETCDIR}
FILES_SUBST+=		OPENLDAP_VARDIR=${OPENLDAP_VARDIR}
FILES_SUBST+=		SLAPD_USER=${SLAPD_USER}
FILES_SUBST+=		LDAP_GROUP=${LDAP_GROUP}

MESSAGE_SUBST+=		SLAPD_USER=${SLAPD_USER}
MESSAGE_SUBST+=		LDAP_GROUP=${LDAP_GROUP}
MESSAGE_SUBST+=		OPENLDAP_VARDIR=${OPENLDAP_VARDIR}
MESSAGE_SUBST+=		OPENLDAP_ETCDIR=${OPENLDAP_ETCDIR}
MESSAGE_SUBST+=		CHOWN=${CHOWN:Q}
MESSAGE_SUBST+=		CHMOD=${CHMOD:Q}

.include "options.mk"

.include "../../databases/openldap/Makefile.common"

.if !empty(PKG_OPTIONS:Mbdb)
CONF_FILES_PERMS+=	${EGDIR}/DB_CONFIG ${OPENLDAP_VARDIR}/openldap-data/DB_CONFIG ${OPENLDAP_FILEPERMS}
DB_CONFIG=		DB_CONFIG
.endif

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
