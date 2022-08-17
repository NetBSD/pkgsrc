# $NetBSD: options.mk,v 1.1 2022/08/17 15:44:16 hauke Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vaultwarden
PKG_SUPPORTED_OPTIONS=		web-vault
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	sqlite pgsql mysql
PKG_SUGGESTED_OPTIONS=		sqlite web-vault

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		web-vault

.if !empty(PKG_OPTIONS:Msqlite)
CARGO_FEATURES+=	sqlite
.  include "../../databases/sqlite/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CARGO_FEATURES+=	postgresql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CARGO_FEATURES+=	mysql
.  include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mweb-vault)
WEB_VAULT_FILE=		bw_web_v${WEB_VAULT_VERS}.tar.gz
WEB_VAULT_VERS=		2022.6.2
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
