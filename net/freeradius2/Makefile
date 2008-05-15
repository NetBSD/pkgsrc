# $NetBSD: Makefile,v 1.1.1.1 2008/05/15 19:43:47 adrianp Exp $

DISTNAME=	freeradius-server-${RADVER}
PKGNAME=	${DISTNAME:S/-server//}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.freeradius.org/
COMMENT=	Free RADIUS server implementation

CONFLICTS+=	freeradius-1.[0-9]*

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=		radiusd-cistron-[0-9]*
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_OLD_DES_API=	YES

BUILD_DEFS=		VARBASE
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
FILES_SUBST+=		RADIUS_USER=${RADIUS_USER:Q}
FILES_SUBST+=		RADIUS_GROUP=${RADIUS_GROUP:Q}
PLIST_SUBST+=		RADVER=${RADVER}
MESSAGE_SRC+=		${WRKDIR}/.MESSAGE_SRC
MESSAGE_SUBST+=		CHOWN=${CHOWN:Q} CHMOD=${CHMOD:Q} VARBASE=${VARBASE}
MESSAGE_SUBST+=		RADIUS_USER=${RADIUS_USER:Q} XARGS=${XARGS:Q}
MESSAGE_SUBST+=		RADIUS_GROUP=${RADIUS_GROUP:Q} FIND=${FIND:Q}

PKG_SYSCONFSUBDIR=	raddb
RCD_SCRIPTS=		radiusd
RADIUS_USER?=		radius
RADIUS_GROUP?=		radius
PKG_GROUPS=		${RADIUS_USER}
PKG_USERS=		${RADIUS_USER}:${RADIUS_GROUP}
PKG_GROUPS_VARS+=	RADIUS_GROUP
PKG_USERS_VARS+=	RADIUS_USER
OWN_DIRS_PERMS+=	${VARBASE}/run/radiusd \
			${RADIUS_USER} ${RADIUS_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/radiusd \
			${RADIUS_USER} ${RADIUS_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/radiusd/radacct \
			${RADIUS_USER} ${RADIUS_GROUP} 0750

RADVER=			2.0.4
EGDIR=			${PREFIX}/share/examples/freeradius

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log/radiusd
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=	--disable-ltdl-install
CONFIGURE_ARGS+=	--with-ltdl-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-ltdl-include=${PREFIX}/include
CONFIGURE_ARGS+=	--without-rlm_ippool
CONFIGURE_ARGS+=	--without-rlm_smb
CONFIGURE_ARGS+=	--without-rlm_sql_iodbc
CONFIGURE_ARGS+=	--without-rlm_sql_oracle
CONFIGURE_ARGS+=	--without-rlm_sql_unixodbc
CONFIGURE_ARGS+=	--quiet
#CONFIGURE_ARGS+=	--without-rlm_eap_peap
#CONFIGURE_ARGS+=	--without-rlm_eap_sim
#CONFIGURE_ARGS+=	--without-rlm_eap_tls
#CONFIGURE_ARGS+=	--without-rlm_eap_ttls

REPLACE_PERL=		scripts/radsqlrelay

SUBST_CLASSES=		make
SUBST_STAGE.make=	post-patch
SUBST_FILES.make=	src/modules/rlm_mschap/Makefile \
			src/modules/rlm_sql/drivers/rlm_sql_postgresql/Makefile.in
SUBST_SED.make=	-e "s|RLM_LDFLAGS	=|RLM_LDFLAGS 	= \
				-L../../../src/lib/.libs/ -lradius|g"
SUBST_SED.make+=	-e "s|RLM_SQL_LIBS	=|RLM_SQL_LIBS	= \
				-L${PREFIX}/lib|g"
SUBST_MESSAGE.make=	Fixing Makefiles.

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	raddb/radiusd.conf.in
SUBST_SED.config=	-e "s|@@RADIUS_USER@@|${RADIUS_USER}|g"
SUBST_SED.config+=	-e "s|@@RADIUS_GROUP@@|${RADIUS_GROUP}|g"
SUBST_MESSAGE.config=	Fixing configuration files.

.include "options.mk"

EGFILES=	certs/demoCA/cacert.pem certs/bootstrap certs/xpextensions \
		certs/client.cnf certs/server.cnf certs/README certs/ca.cnf \
		sql/mssql/dialup.conf sql/mssql/schema.sql \
		sql/mysql/dialup.conf sql/mysql/nas.sql sql/mysql/ippool.conf \
		sql/mysql/schema.sql sql/mysql/counter.conf \
		sql/mysql/ippool.sql sql/oracle/dialup.conf sql/oracle/nas.sql \
		sql/oracle/schema.sql sql/oracle/ippool.sql \
		sql/postgresql/dialup.conf sql/postgresql/nas.sql \
		sql/postgresql/voip-postpaid.conf sql/postgresql/ippool.conf \
		sql/postgresql/schema.sql sql/postgresql/ippool.sql \
		sql/postgresql/cisco_h323_db_schema.sql \
		sql/postgresql/counter.conf sql/postgresql/admin.sql \
		sql/postgresql/update_radacct_group_trigger.sql policy.txt \
		experimental.conf radiusd.conf otp.conf policy.conf \
		preproxy_users users vmpsd.conf.in acct_users snmp.conf \
		ldap.attrmap clients.conf huntgroups sql.conf sqlippool.conf \
		sites-available/inner-tunnel sites-available/example \
		sites-available/buffered-sql sites-available/default \
		sites-available/vmps sites-available/README \
		sites-available/proxy-inner-tunnel \
		sites-available/copy-acct-to-home-server attrs.pre-proxy \
		sites-available/dhcp sites-available/robust-proxy-accounting \
		sites-available/virtual.example.com sql/mysql/admin.sql \
		eap.conf attrs.accounting_response hints attrs.access_reject \
		templates.conf attrs proxy.conf dictionary

EGDIRS=		certs certs/demoCA sql sql/mssql sql/mysql sql/oracle \
		sql/postgresql sites-available

.for f in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${RADIUS_USER} ${RADIUS_GROUP} 0640
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--without-threads
.endif

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "pth"
.include "../../devel/pthread-sem/buildlink3.mk"
SUBST_SED.make+=	-e 's|@ldap_ldflags@|@ldap_ldflags@ \
			${PTHREAD_LDFLAGS:M*:Q} ${PTHREAD_LIBS:M*:Q} -lsemaphore|g'
.endif

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "native"
SUBST_SED.make+=	-e 's|@ldap_ldflags@|@ldap_ldflags@ \
			${PTHREAD_LDFLAGS:M*:Q} ${PTHREAD_LIBS:M*:Q}|g'
.endif

.if ${MACHINE_ARCH} == "amd64"
CFLAGS+= -fPIC
.endif

post-build:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC
	${CP} ${PKGDIR:Q}/MESSAGE ${WRKDIR:Q}/.MESSAGE_SRC

.	if !empty(PKG_OPTIONS:Mpam)
		${CP} ${PKGDIR:Q}/MESSAGE.pam ${WRKDIR:Q}/.MESSAGE_SRC.pam
.	endif

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.	for d in ${EGDIRS}
		${INSTALL_DATA_DIR} ${EGDIR}/${d}
.	endfor

.	for f in ${EGFILES}
		${INSTALL_DATA} ${WRKSRC}/raddb/${f} ${EGDIR}/${f}
.	endfor

	${INSTALL_DATA} ${WRKSRC}/src/modules/rlm_perl/example.pl ${EGDIR}

.	for d in ${EGDIRS}
		${MKDIR} ${PKG_SYSCONFDIR}/${d}
.	endfor

	${CHOWN} ${RADIUS_USER}:${RADIUS_GROUP} ${PKG_SYSCONFDIR}/certs
	${CHOWN} ${RADIUS_USER}:${RADIUS_GROUP} ${PKG_SYSCONFDIR}/certs/demoCA
	${CHMOD} 0750 ${PKG_SYSCONFDIR}/certs
	${CHMOD} 0750 ${PKG_SYSCONFDIR}/certs/demoCA

.include "../../mk/bsd.pkg.mk"
