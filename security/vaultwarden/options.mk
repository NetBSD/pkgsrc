# $NetBSD: options.mk,v 1.9 2026/02/24 10:27:33 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vaultwarden
PKG_SUPPORTED_OPTIONS=		web-vault
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	sqlite pgsql mysql
PKG_SUGGESTED_OPTIONS=		sqlite web-vault

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		web-vault

.if !empty(PKG_OPTIONS:Msqlite)
CARGO_FEATURES+=	sqlite
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib
.  include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CARGO_FEATURES+=	postgresql
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.${PGSQL_TYPE}}/lib
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CARGO_FEATURES+=	mysql
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mysql-client}/lib
.  include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mweb-vault)
WEB_VAULT_FILE=		bw_web_v${WEB_VAULT_VERS}.tar.gz
WEB_VAULT_VERS=		2026.1.1
DISTFILES+=		${WEB_VAULT_FILE}
SITES.${WEB_VAULT_FILE}= ${MASTER_SITE_GITHUB:=dani-garcia/bw_web_builds/releases/download/v${WEB_VAULT_VERS}/}

WEB_VAULT_DIR=		share/vaultwarden/web-vault
INSTALLATION_DIRS+=	${WEB_VAULT_DIR}

PLIST.web-vault=	yes

USE_TOOLS+=		pax

post-install:
	(cd ${WRKDIR}/web-vault && \
		${PAX} -rw . ${DESTDIR}${PREFIX}/${WEB_VAULT_DIR} )
.endif
