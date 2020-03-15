# $NetBSD: options.mk,v 1.7 2020/03/15 16:00:55 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.redmine

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mssql mysql pgsql sqlite3
PKG_SUPPORTED_OPTIONS+=		unicorn

PKG_SUGGESTED_OPTIONS=	mysql unicorn

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		mssql mysql pgsql sqlite3 unicorn

###
### Use mysql, pgsql, or sqlite3 backend
###
MSSQL_DISTFILES=	activerecord-sqlserver-adapter-5.2.0.gem tiny_tds-2.1.2.gem
MYSQL_DISTFILES=	mysql2-0.5.3.gem
PGSQL_DISTFILES=	pg-1.1.4.gem
SQLITE3_DISTFILES=	sqlite3-1.3.13.gem

.if make (distinfo) || make (mdi) # for checksum generation only
GEMS_DISTFILES+=	${MSSQL_DISTFILES}
GEMS_DISTFILES+=	${MYSQL_DISTFILES}
GEMS_DISTFILES+=	${PGSQL_DISTFILES}
GEMS_DISTFILES+=	${SQLITE3_DISTFILES}
.elif !empty(PKG_OPTIONS:Mmssql)
GEMS_DISTFILES+=	${MSSQL_DISTFILES}
.include "../../databases/freetds/buildlink3.mk"
PLIST.mssql=		yes
.elif !empty(PKG_OPTIONS:Mmysql)
GEMS_DISTFILES+=	${MYSQL_DISTFILES}
.include "../../mk/mysql.buildlink3.mk"
PLIST.mysql=		yes
.elif !empty(PKG_OPTIONS:Mpgsql)
GEMS_DISTFILES+=	${PGSQL_DISTFILES}
.include "../../mk/pgsql.buildlink3.mk"
CHECK_INTERPRETER_SKIP+=	${RM_DIR}/gems/gems/pg-*/spec/*
CHECK_INTERPRETER_SKIP+=	${RM_DIR}/gems/gems/pg-*/spec/pg/*
PLIST.pgsql=		yes
.elif !empty(PKG_OPTIONS:Msqlite3)
GEMS_DISTFILES+=	${SQLITE3_DISTFILES}
.include "../../databases/sqlite3/buildlink3.mk"
PLIST.sqlite3=		yes
.endif

###
### Use Unicorn web server
###
.if !empty(PKG_OPTIONS:Municorn) || make (distinfo) || make (mdi)

GEMS_DISTFILES+=	kgio-2.11.3.gem raindrops-0.19.1.gem unicorn-5.5.3.gem

PLIST.unicorn=		yes

SUBST_CLASSES+=			prefix
SUBST_STAGE.prefix=		pre-configure
SUBST_MESSAGE.prefix=		Setting PREFIX and RUBY_PKGPREFIX.
SUBST_FILES.prefix=		${WRKDIR}/unicorn.rb
SUBST_VARS.prefix=		RUBY_PKGPREFIX
SUBST_VARS.prefix+=		PREFIX

RCD_SCRIPTS+=	redmine_unicorn${RUBY_SUFFIX}
RCD_SCRIPT_SRC.redmine_unicorn${RUBY_SUFFIX}=	${FILESDIR}/redmine_unicorn.sh

CONF_FILES+=	${EGDIR}/unicorn.rb.example \
		${PREFIX}/${RM_DIR}/app/config/unicorn.rb

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
