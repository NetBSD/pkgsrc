# $NetBSD: Makefile,v 1.110.2.1 2006/05/22 12:58:24 salo Exp $

DISTNAME=	openldap-2.3.23
SVR4_PKGNAME=	oldap
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.OpenLDAP.org/
COMMENT=	Lightweight Directory Access Protocol server and client

CONFLICTS+=		ldapsdk-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		test

MAKE_ENV+=		LIBMODE=${LIBMODE:Q}
OPENLDAP_ETCDIR=	${PKG_SYSCONFDIR}/openldap
OPENLDAP_MODULEDIR=	${PREFIX}/lib/openldap
OPENLDAP_VARDIR=	${VARBASE}/openldap
FILES_SUBST+=		OPENLDAP_ETCDIR=${OPENLDAP_ETCDIR:Q}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# the internal avl_* prototypes conflict with those in <sys/avl.h> which
# is included by another system header file on Solaris, so subst them.
.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		conflict
SUBST_STAGE.conflict=	post-patch
SUBST_FILES.conflict=	${WRKSRC}/*/*.h
SUBST_FILES.conflict+=	${WRKSRC}/*/*/*.c ${WRKSRC}/*/*/*/*.c
SUBST_SED.conflict+=	-e 's,avl_free,openldap_avl_free,g'
SUBST_SED.conflict+=	-e 's,avl_insert,openldap_avl_insert,g'
SUBST_SED.conflict+=	-e 's,avl_delete,openldap_avl_delete,g'
SUBST_SED.conflict+=	-e 's,avl_find,openldap_avl_find,g'
SUBST_SED.conflict+=	-e 's,avl_find2,openldap_avl_find2,g'
SUBST_MESSAGE.conflict=	Fixing conflicting function prototypes.
.endif

CPPFLAGS.Darwin+=	-DBIND_8_COMPAT

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${OPENLDAP_VARDIR:Q}
CONFIGURE_ARGS+=	--enable-dynamic   # link servers against shared libs
CONFIGURE_ARGS+=	--with-tls=openssl

# SLAPD options
CONFIGURE_ARGS+=	--enable-crypt
.if !empty(PKG_OPTIONS:Msasl)
CONFIGURE_ARGS+=	--enable-spasswd
.endif
CONFIGURE_ARGS+=	--enable-wrappers

# SLAPD backends
CONFIGURE_ARGS+=	--enable-dnssrv
CONFIGURE_ARGS+=	--enable-ldap
CONFIGURE_ARGS+=	--enable-ldbm
CONFIGURE_ARGS+=	--enable-meta
CONFIGURE_ARGS+=	--enable-monitor
CONFIGURE_ARGS+=	--enable-null
CONFIGURE_ARGS+=	--enable-passwd
CONFIGURE_ARGS+=	--enable-shell

# SLAPD (stackable) overlays
CONFIGURE_ARGS+=	--enable-overlays

OPENLDAP_FILEPERMS=	${ROOT_USER} ${ROOT_GROUP} 0600
OPENLDAP_DIRPERMS=	${ROOT_USER} ${ROOT_GROUP} 0700

EGDIR=			${PREFIX}/share/examples/openldap
MAKE_DIRS=		${OPENLDAP_ETCDIR} ${OPENLDAP_ETCDIR}/schema
OWN_DIRS=		${OPENLDAP_VARDIR} ${OPENLDAP_VARDIR}/run
OWN_DIRS_PERMS=		${OPENLDAP_VARDIR}/openldap-data ${OPENLDAP_DIRPERMS}
OWN_DIRS_PERMS+=	${OPENLDAP_VARDIR}/openldap-slurp ${OPENLDAP_DIRPERMS}

CNFS=			ldap.conf ${CNFS_SCHEMAS_cmd:sh}
CNFS_SCHEMAS_cmd=	${SED} -ne "/\.ldif$$/p;/\.schema$$/p" ${PKGDIR}/PLIST | ${SED} -e "s|share/examples/openldap/||"
CNFS_PERMS=		slapd.conf

CONF_FILES=		# empty
CONF_FILES_PERMS=	# empty
.for FILE in ${CNFS}
CONF_FILES+=		${EGDIR}/${FILE} ${OPENLDAP_ETCDIR}/${FILE}
.endfor
.for FILE in ${CNFS_PERMS}
CONF_FILES_PERMS+=	${EGDIR}/${FILE} ${OPENLDAP_ETCDIR}/${FILE}	\
			${OPENLDAP_FILEPERMS}
.endfor
CONF_FILES_PERMS+=	${EGDIR}/DB_CONFIG				\
			${OPENLDAP_VARDIR}/openldap-data/DB_CONFIG	\
			${OPENLDAP_FILEPERMS}
RCD_SCRIPTS=		slapd

PTHREAD_OPTS+=		require

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if ${PTHREAD_TYPE} == "native"
CONFIGURE_ARGS+=	--with-threads
.elif ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-threads=pth
#
# Don't use a larger FD_SETSIZE than GNU Pth can handle (value taken from
# pth.h header).
#
PTH_FDSETSIZE_cmd=	\
	if ${TEST} -f ${BUILDLINK_PREFIX.pth:Q}/include/pth.h; then	\
		${AWK} '/if FD_SETSIZE >/ { print $$4 }'		\
			${BUILDLINK_PREFIX.pth}/include/pth.h;		\
	else								\
		${ECHO} 0;						\
	fi
CPPFLAGS+=		-DOPENLDAP_FD_SETSIZE=${PTH_FDSETSIZE_cmd:sh:Q}
.endif
RCD_SCRIPTS+=		slurpd

MAKE_FLAGS+=		moduledir=${OPENLDAP_MODULEDIR:Q}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

# Set the correct file modes for the example config files.
post-install:
.for _file_ in ${CNFS} ${CNFS_PERMS}
	${CHMOD} ${SHAREMODE} ${EGDIR}/${_file_}
	${RM} -f ${EGDIR}/${_file_}.default
.endfor
	${CHMOD} ${SHAREMODE} ${EGDIR}/DB_CONFIG

.include "../../mk/bsd.pkg.mk"
