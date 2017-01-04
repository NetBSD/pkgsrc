# $NetBSD: options.mk,v 1.5 2017/01/04 23:05:12 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.redmine

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite3
PKG_SUPPORTED_OPTIONS+=		unicorn

PKG_SUGGESTED_OPTIONS=	mysql unicorn

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mysql pgsql sqlite3

###
### Use mysql, pgsql, or sqlite3 backend
###
MYSQL_DISTFILE=		mysql2-0.3.21.gem
PGSQL_DISTFILE=		pg-0.18.4.gem
SQLITE3_DISTFILE=	sqlite3-1.3.12.gem

.if make (distinfo) || make (mdi) # for checksum generation only
GEMS_DISTFILES+=	${MYSQL_DISTFILE}
GEMS_DISTFILES+=	${PGSQL_DISTFILE}
GEMS_DISTFILES+=	${SQLITE3_DISTFILE}
.elif !empty(PKG_OPTIONS:Mmysql)
GEMS_DISTFILES+=	${MYSQL_DISTFILE}
.include "../../mk/mysql.buildlink3.mk"
RM_PLIST_SRC+=		PLIST.mysql
.elif !empty(PKG_OPTIONS:Mpgsql)
GEMS_DISTFILES+=	${PGSQL_DISTFILE}
.include "../../mk/pgsql.buildlink3.mk"
CHECK_INTERPRETER_SKIP+=	${RM_DIR}/gems/gems/pg-*/spec/*
CHECK_INTERPRETER_SKIP+=	${RM_DIR}/gems/gems/pg-*/spec/pg/*
RM_PLIST_SRC+=		PLIST.pgsql
.elif !empty(PKG_OPTIONS:Msqlite3)
GEMS_DISTFILES+=	${SQLITE3_DISTFILE}
.include "../../databases/sqlite3/buildlink3.mk"
RM_PLIST_SRC+=		PLIST.sqlite3
.endif

###
### Use Unicorn web server
###
.if !empty(PKG_OPTIONS:Municorn) || make (distinfo) || make (mdi)
RM_PLIST_SRC+=		PLIST.unicorn
GEMS_DISTFILES+=	kgio-2.11.0.gem \
			raindrops-0.17.0.gem \
			unicorn-5.2.0.gem

SUBST_CLASSES+=			prefix
SUBST_STAGE.prefix=		pre-configure
SUBST_MESSAGE.prefix=		Setting PREFIX and RUBY_PKGPREFIX.
SUBST_FILES.prefix=		${WRKDIR}/unicorn.rb
SUBST_SED.prefix+=		-e "s|@RUBY_PKGPREFIX@|${RUBY_PKGPREFIX}|g"
SUBST_VARS.prefix+=		PREFIX

RCD_SCRIPTS+=	redmine_unicorn${RUBY_SUFFIX}
RCD_SCRIPT_SRC.redmine_unicorn${RUBY_SUFFIX}=	${FILESDIR}/redmine_unicorn.sh

CONF_FILES+=	${EGDIR}/unicorn.rb.example \
		${PREFIX}/${RM_DIR}/app/config/unicorn.rb

PLIST_SRC=	${PLIST_SRC_DFLT} ${RM_PLIST_SRC}

post-extract:
	${CP} ${FILESDIR}/unicorn.rb ${WRKDIR}/unicorn.rb

.PHONY: unicorn-post-install
unicorn-post-install:
	${CP} ${WRKDIR}/unicorn.rb \
		${DESTDIR}${EGDIR}/unicorn.rb.example
	${CP} ${FILESDIR}/Gemfile.local \
		${DESTDIR}${PREFIX}/${RM_DIR}/app
.endif
.PHONY: unicorn-post-install
unicorn-post-install:
# nothing
