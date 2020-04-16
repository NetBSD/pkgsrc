# $NetBSD: Makefile,v 1.107 2020/04/16 15:49:30 jperkin Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/-server//}
PKGREVISION=	1
COMMENT=	Free RADIUS server implementation

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-logdir=${VARBASE}/log/radiusd
CONFIGURE_ARGS+=	--without-rlm_eap_ikev2
CONFIGURE_ARGS+=	--without-rlm_eap_tnc
CONFIGURE_ARGS+=	--without-rlm_sql_freetds
CONFIGURE_ARGS+=	--without-rlm_sql_sqlite
CONFIGURE_ARGS+=	--without-rlm_cache_memcached
CONFIGURE_ARGS+=	--without-rlm_krb5
CONFIGURE_ARGS+=	--without-rlm_ldap
CONFIGURE_ARGS+=	--without-rlm_perl
CONFIGURE_ARGS+=	--without-rlm_python
CONFIGURE_ARGS+=	--without-rlm_redis
CONFIGURE_ARGS+=	--without-rlm_rediswho
CONFIGURE_ARGS+=	--without-rlm_rest
CONFIGURE_ARGS+=	--without-rlm_ruby
CONFIGURE_ARGS+=	--without-rlm_sql_iodbc
CONFIGURE_ARGS+=	--without-rlm_sql_mysql
CONFIGURE_ARGS+=	--without-rlm_sql_oracle
CONFIGURE_ARGS+=	--without-rlm_sql_postgresql
CONFIGURE_ARGS+=	--without-rlm_sql_unixodbc

RCD_SCRIPTS=		radiusd
SMF_METHODS=		radiusd
RADIUS_GROUP?=		radiusd
RADIUS_USER?=		radiusd
PKG_GROUPS=		${RADIUS_GROUP}
PKG_USERS=		${RADIUS_USER}:${RADIUS_GROUP}
PKG_HOME.${RADIUS_USER}= ${VARBASE}/log/radiusd

OWN_DIRS_PERMS+=	${VARBASE}/log/radiusd \
			${RADIUS_USER} ${RADIUS_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/run/radiusd \
			${RADIUS_USER} ${RADIUS_GROUP} 0750

PKG_SYSCONFSUBDIR=	raddb

SUBST_CLASSES+=		secconf
SUBST_STAGE.secconf=	post-configure
SUBST_MESSAGE.secconf=	Substituting user and group in radiusd.conf
SUBST_FILES.secconf=	raddb/radiusd.conf
SUBST_VARS.secconf=	RADIUS_USER RADIUS_GROUP

FILES_SUBST+=		RADIUS_USER=${RADIUS_USER} RADIUS_GROUP=${RADIUS_GROUP}
MESSAGE_SUBST+=		BOOTSTRAP=${PKG_SYSCONFDIR}/certs/bootstrap

EGDIR=			${PREFIX}/share/examples/freeradius

EGFILES=		certs/ca.cnf certs/client.cnf certs/inner-server.cnf \
			certs/Makefile certs/README certs/server.cnf \
			certs/xpextensions \
			clients.conf dictionary experimental.conf \
			mods-available/abfab_psk_sql mods-available/always \
			mods-available/attr_filter mods-available/cache \
			mods-available/cache_eap mods-available/chap \
			mods-available/couchbase mods-available/counter \
			mods-available/cui mods-available/date \
			mods-available/detail mods-available/detail.example.com \
			mods-available/detail.log mods-available/dhcp \
			mods-available/dhcp_sqlippool mods-available/digest \
			mods-available/dynamic_clients mods-available/eap \
			mods-available/echo mods-available/etc_group \
			mods-available/exec mods-available/expiration \
			mods-available/expr mods-available/files \
			mods-available/idn mods-available/inner-eap \
			mods-available/ippool mods-available/krb5 \
			mods-available/ldap mods-available/linelog \
			mods-available/logintime mods-available/mac2ip \
			mods-available/mac2vlan mods-available/mschap \
			mods-available/ntlm_auth mods-available/opendirectory \
			mods-available/otp mods-available/pam \
			mods-available/pap mods-available/passwd \
			mods-available/perl mods-available/preprocess \
			mods-available/python mods-available/radutmp \
			mods-available/README.rst mods-available/realm \
			mods-available/redis mods-available/rediswho \
			mods-available/replicate mods-available/rest \
			mods-available/smbpasswd mods-available/smsotp \
			mods-available/soh mods-available/sometimes \
			mods-available/sql mods-available/sqlcounter \
			mods-available/sqlippool mods-available/sradutmp \
			mods-available/unbound mods-available/unix \
			mods-available/unpack mods-available/utf8 \
			mods-available/wimax mods-available/yubikey \
			mods-config/attr_filter/access_challenge \
			mods-config/attr_filter/access_reject \
			mods-config/attr_filter/accounting_response \
			mods-config/attr_filter/post-proxy \
			mods-config/attr_filter/pre-proxy \
			mods-config/files/accounting \
			mods-config/files/authorize \
			mods-config/files/pre-proxy \
			mods-config/perl/example.pl \
			mods-config/preprocess/hints \
			mods-config/preprocess/huntgroups \
			mods-config/README.rst \
			mods-config/sql/counter/mysql/dailycounter.conf \
			mods-config/sql/counter/mysql/expire_on_login.conf \
			mods-config/sql/counter/mysql/monthlycounter.conf \
			mods-config/sql/counter/mysql/noresetcounter.conf \
			mods-config/sql/counter/postgresql/dailycounter.conf \
			mods-config/sql/counter/postgresql/expire_on_login.conf \
			mods-config/sql/counter/postgresql/monthlycounter.conf \
			mods-config/sql/counter/postgresql/noresetcounter.conf \
			mods-config/sql/counter/sqlite/dailycounter.conf \
			mods-config/sql/counter/sqlite/expire_on_login.conf \
			mods-config/sql/counter/sqlite/monthlycounter.conf \
			mods-config/sql/counter/sqlite/noresetcounter.conf \
			mods-config/sql/cui/mysql/queries.conf \
			mods-config/sql/cui/mysql/schema.sql \
			mods-config/sql/cui/postgresql/queries.conf \
			mods-config/sql/cui/postgresql/schema.sql \
			mods-config/sql/cui/sqlite/queries.conf \
			mods-config/sql/cui/sqlite/schema.sql \
			mods-config/sql/ippool/mysql/queries.conf \
			mods-config/sql/ippool/mysql/schema.sql \
			mods-config/sql/ippool/oracle/queries.conf \
			mods-config/sql/ippool/oracle/schema.sql \
			mods-config/sql/ippool/postgresql/queries.conf \
			mods-config/sql/ippool/postgresql/schema.sql \
			mods-config/sql/ippool/sqlite/queries.conf \
			mods-config/sql/ippool/sqlite/schema.sql \
			mods-config/sql/ippool-dhcp/mysql/queries.conf \
			mods-config/sql/ippool-dhcp/mysql/schema.sql \
			mods-config/sql/ippool-dhcp/oracle/queries.conf \
			mods-config/sql/ippool-dhcp/oracle/schema.sql \
			mods-config/sql/ippool-dhcp/sqlite/queries.conf \
			mods-config/sql/ippool-dhcp/sqlite/schema.sql \
			mods-config/sql/main/mssql/queries.conf \
			mods-config/sql/main/mssql/schema.sql \
			mods-config/sql/main/mysql/extras/wimax/queries.conf \
			mods-config/sql/main/mysql/extras/wimax/schema.sql \
			mods-config/sql/main/mysql/queries.conf \
			mods-config/sql/main/mysql/schema.sql \
			mods-config/sql/main/mysql/setup.sql \
			mods-config/sql/main/ndb/README \
			mods-config/sql/main/ndb/schema.sql \
			mods-config/sql/main/ndb/setup.sql \
			mods-config/sql/main/oracle/queries.conf \
			mods-config/sql/main/oracle/schema.sql \
			mods-config/sql/main/postgresql/extras/cisco_h323_db_schema.sql \
			mods-config/sql/main/postgresql/extras/voip-postpaid.conf \
			mods-config/sql/main/postgresql/queries.conf \
			mods-config/sql/main/postgresql/schema.sql \
			mods-config/sql/main/postgresql/setup.sql \
			mods-config/sql/main/sqlite/queries.conf \
			mods-config/sql/main/sqlite/schema.sql \
			mods-config/unbound/default.conf \
			panic.gdb policy.d/abfab-tr policy.d/accounting \
			policy.d/canonicalization policy.d/control policy.d/cui \
			policy.d/debug policy.d/dhcp policy.d/eap policy.d/filter \
			policy.d/moonshot-targeted-ids policy.d/operator-name \
			proxy.conf radiusd.conf README.rst \
			sites-available/abfab-tls sites-available/abfab-tr-idp \
			sites-available/buffered-sql sites-available/challenge \
			sites-available/channel_bindings sites-available/check-eap-tls \
			sites-available/coa sites-available/control-socket \
			sites-available/copy-acct-to-home-server \
			sites-available/decoupled-accounting \
			sites-available/default \
			sites-available/dhcp \
			sites-available/dhcp.relay \
			sites-available/dynamic-clients \
			sites-available/example \
			sites-available/inner-tunnel \
			sites-available/originate-coa \
			sites-available/proxy-inner-tunnel \
			sites-available/README \
			sites-available/robust-proxy-accounting \
			sites-available/soh \
			sites-available/status \
			sites-available/tls \
			sites-available/virtual.example.com \
			users templates.conf trigger.conf

EGDIRS=			certs mods-available mods-config mods-config/attr_filter mods-config/files \
			mods-config/perl mods-config/preprocess mods-config/sql mods-config/sql/counter \
			mods-config/sql/counter/mysql mods-config/sql/counter/postgresql \
			mods-config/sql/counter/sqlite mods-config/sql/cui mods-config/sql/cui/mysql \
			mods-config/sql/cui/postgresql mods-config/sql/cui/sqlite mods-config/sql/ippool \
			mods-config/sql/ippool-dhcp mods-config/sql/ippool-dhcp/mysql \
			mods-config/sql/ippool-dhcp/oracle mods-config/sql/ippool-dhcp/sqlite \
			mods-config/sql/ippool/mysql mods-config/sql/ippool/oracle \
			mods-config/sql/ippool/postgresql mods-config/sql/ippool/sqlite \
			mods-config/sql/main mods-config/sql/main/mssql mods-config/sql/main/mysql \
			mods-config/sql/main/mysql/extras mods-config/sql/main/mysql/extras/wimax \
			mods-config/sql/main/ndb mods-config/sql/main/oracle \
			mods-config/sql/main/postgresql mods-config/sql/main/postgresql/extras \
			mods-config/sql/main/sqlite mods-config/unbound mods-enabled \
			policy.d sites-available sites-enabled

REPLACE_PERL+=		scripts/sql/radsqlrelay \
			src/modules/rlm_counter/rad_counter

.for f in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f} \
			${RADIUS_USER} ${RADIUS_GROUP} 0640
.endfor
CONF_FILES_PERMS+=	${EGDIR}/certs/bootstrap ${PKG_SYSCONFDIR}/certs/bootstrap \
			${RADIUS_USER} ${RADIUS_GROUP} 0750

.for d in ${EGDIRS}
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/${d} ${RADIUS_USER} ${RADIUS_GROUP} 0750
.endfor

INSTALL_MAKE_FLAGS+=	raddbdir=${EGDIR}

TEST_TARGET=		test
TEST_MAKE_FLAGS+=	EAPOL_TEST=""

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/*.a ${DESTDIR}${PREFIX}/lib/*.la

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
