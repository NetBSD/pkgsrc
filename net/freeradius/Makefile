# $NetBSD: Makefile,v 1.116 2022/07/20 01:19:55 gutteridge Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/-server//}
PKGREVISION=	3
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

REPLACE_PERL+=		src/modules/rlm_counter/rad_counter
REPLACE_PERL+=		scripts/sql/radsqlrelay
REPLACE_PERL+=		scripts/sql/rlm_sqlippool_tool

EGDIR=		${PREFIX}/share/examples/freeradius

.include "config.mk"

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
