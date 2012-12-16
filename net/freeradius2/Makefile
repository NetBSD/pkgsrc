# $NetBSD: Makefile,v 1.28 2012/12/16 01:52:28 obache Exp $

DISTNAME=	freeradius-server-${RADVER}
PKGNAME=	${DISTNAME:S/-server//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freeradius.org/
COMMENT=	Free RADIUS server implementation
LICENSE=	gnu-gpl-v2

CONFLICTS+=		radiusd-cistron-[0-9]*
CONFLICTS+=		freeradius<2.0
USE_TOOLS+=		gmake perl:run
USE_LIBTOOL=		yes
USE_OLD_DES_API=	yes
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE
FILES_SUBST+=		RADIUS_USER=${RADIUS_USER}
FILES_SUBST+=		RADIUS_GROUP=${RADIUS_GROUP}
PLIST_SUBST+=		RADVER=${RADVER}
MESSAGE_SRC+=		${WRKDIR}/.MESSAGE_SRC
MESSAGE_SUBST+=		CHOWN=${CHOWN:Q} CHMOD=${CHMOD:Q} VARBASE=${VARBASE}
MESSAGE_SUBST+=		RADIUS_USER=${RADIUS_USER} XARGS=${XARGS:Q}
MESSAGE_SUBST+=		RADIUS_GROUP=${RADIUS_GROUP} FIND=${FIND:Q}

PKG_SYSCONFSUBDIR=	raddb
RCD_SCRIPTS=		radiusd
RADIUS_USER?=		radius
RADIUS_GROUP?=		radius
PKG_GROUPS=		${RADIUS_USER}
PKG_USERS=		${RADIUS_USER}:${RADIUS_GROUP}
PKG_GROUPS_VARS+=	RADIUS_GROUP
PKG_USERS_VARS=		RADIUS_USER
OWN_DIRS_PERMS+=	${VARBASE}/run/radiusd \
			${RADIUS_USER} ${RADIUS_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/radiusd \
			${RADIUS_USER} ${RADIUS_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/radiusd/radacct \
			${RADIUS_USER} ${RADIUS_GROUP} 0750

RADVER=			2.2.0
EGDIR=			${PREFIX}/share/examples/freeradius

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--quiet
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log/radiusd
CONFIGURE_ARGS+=	--with-system-libltdl
CONFIGURE_ARGS+=	--with-system-libtool
CONFIGURE_ARGS+=	--without-rlm_python
CONFIGURE_ARGS+=	--without-rlm_smb
CONFIGURE_ARGS+=	--without-rlm_sql_oracle
CONFIGURE_ARGS+=	--without-rlm_sql_unixodbc
MAKE_ENV+=		R=${DESTDIR}

REPLACE_PERL=		src/modules/rlm_counter/rad_counter
REPLACE_PERL+=		scripts/radsqlrelay

SUBST_CLASSES+=		make
SUBST_STAGE.make=	post-patch
SUBST_FILES.make=	src/modules/rlm_sql/drivers/rlm_sql_postgresql/Makefile.in
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

EGFILES=acct_users attrs attrs.access_reject attrs.accounting_response \
	attrs.pre-proxy certs/README certs/bootstrap certs/ca.cnf \
	certs/client.cnf certs/demoCA/cacert.pem certs/server.cnf \
	certs/xpextensions clients.conf dictionary eap.conf experimental.conf \
	hints huntgroups ldap.attrmap modules/acct_unique modules/always \
	modules/attr_filter modules/attr_rewrite modules/chap modules/checkval \
	modules/counter modules/detail modules/detail.example.com \
	modules/detail.log modules/digest modules/echo modules/etc_group \
	modules/exec modules/expiration modules/expr modules/files \
	modules/inner-eap modules/ippool modules/krb5 modules/ldap \
	modules/linelog modules/logintime modules/mac2ip modules/mac2vlan \
	modules/mschap modules/otp modules/pam modules/pap modules/passwd \
	modules/perl modules/policy modules/preprocess modules/radutmp \
	modules/realm modules/smbpasswd modules/smsotp modules/sql_log \
	modules/sqlcounter_expire_on_login modules/sradutmp modules/unix \
	modules/wimax policy.conf policy.txt preproxy_users proxy.conf \
	radiusd.conf sites-available/README sites-available/buffered-sql \
	sites-available/control-socket \
	sites-available/copy-acct-to-home-server \
	sites-available/decoupled-accounting sites-available/default \
	sites-available/dhcp sites-available/dynamic-clients \
	sites-available/example sites-available/inner-tunnel \
	sites-available/originate-coa sites-available/proxy-inner-tunnel \
	sites-available/robust-proxy-accounting sites-available/status \
	sites-available/virtual.example.com sites-available/vmps sql.conf \
	sql/mssql/dialup.conf sql/mssql/schema.sql sql/mysql/admin.sql \
	sql/mysql/counter.conf sql/mysql/dialup.conf sql/mysql/ippool.conf \
	sql/mysql/ippool.sql sql/mysql/nas.sql sql/mysql/schema.sql \
	sql/mysql/wimax.conf sql/mysql/wimax.sql sql/oracle/dialup.conf \
	sql/oracle/ippool.conf sql/oracle/ippool.sql sql/oracle/msqlippool.txt \
	sql/oracle/nas.sql sql/oracle/schema.sql sql/postgresql/admin.sql \
	sql/postgresql/cisco_h323_db_schema.sql sql/postgresql/counter.conf \
	sql/postgresql/dialup.conf sql/postgresql/ippool.conf \
	sql/postgresql/ippool.sql sql/postgresql/nas.sql \
	sql/postgresql/schema.sql \
	sql/postgresql/update_radacct_group_trigger.sql \
	sql/postgresql/voip-postpaid.conf sqlippool.conf templates.conf users
EGDIRS=	certs certs/demoCA modules sql sql/mssql sql/mysql sql/oracle \
	sql/postgresql sites-available sites-enabled

.for f in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${RADIUS_USER} ${RADIUS_GROUP} 0640
.endfor

.for d in ${EGDIRS}
INSTALLATION_DIRS+=	${EGDIR}/${d}
.endfor

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/certs ${RADIUS_USER} \
			${RADIUS_GROUP} 750
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/certs/demoCA ${RADIUS_USER} \
			${RADIUS_GROUP} 750
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/modules ${RADIUS_USER} \
			${RADIUS_GROUP} 750
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/sites-enabled ${RADIUS_USER} \
			${RADIUS_GROUP} 750

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

post-build:
	${CP} ${PKGDIR}/MESSAGE ${WRKDIR}/.MESSAGE_SRC
.if !empty(PKG_OPTIONS:Mpam)
	${CP} ${PKGDIR}/MESSAGE.pam ${WRKDIR}/.MESSAGE_SRC.pam
.endif

post-install:
.for f in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/raddb/${f} ${DESTDIR}${EGDIR}/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/modules/rlm_perl/example.pl ${DESTDIR}${EGDIR}

.include "../../devel/libltdl/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
