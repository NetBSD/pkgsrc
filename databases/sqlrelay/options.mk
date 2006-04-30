# $NetBSD: options.mk,v 1.5 2006/04/30 16:01:21 joerg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sqlrelay
PKG_SUPPORTED_OPTIONS+= mysql pgsql sqlite odbc freetds perl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mperl)
PERL5_PACKLIST=		auto/SQLRelay/Connection/.packlist
PERL5_PACKLIST+=	auto/SQLRelay/Cursor/.packlist
PERL5_PACKLIST+=	auto/DBD/SQLRelay/.packlist

CONFIGURE_ARGS+=	--with-perl-site-arch=${PERL5_INSTALLVENDORARCH:Q}
CONFIGURE_ARGS+=	--with-perl-site-lib=${PERL5_INSTALLVENDORLIB:Q}
CONFIGURE_ARGS+=	--with-perl-install-man3-dir=${PERL5_INSTALLVENDORMAN3DIR:Q}

PLIST_SUBST+=	COND_PERL=""

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/packlist.mk"
.include "../../lang/perl5/vars.mk"

.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUBST+=	COND_PERL="@comment "
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client:Q}
PLIST_SUBST+=	COND_MYSQL=""
.include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUBST+=	COND_MYSQL="@comment "
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX:Q}
.include "../../mk/pgsql.buildlink3.mk"
PLIST_SUBST+=	COND_PGSQL=""
.else
CONFIGURE_ARGS+=	--disable-postgresql
PLIST_SUBST+=	COND_PGSQL="@comment "
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite3:Q}
PLIST_SUBST+=	COND_SQLITE=""
.include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sqlite
PLIST_SUBST+=	COND_SQLITE="@comment "
.endif

.if !empty(PKG_OPTIONS:Modbc)
CONFIGURE_ARGS+=	--with-odbc=${BUILDLINK_PREFIX.unixodbc:Q}
PLIST_SUBST+=	COND_ODBC=""
.include "../../databases/unixodbc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-odbc
PLIST_SUBST+=	COND_ODBC="@comment "
.endif

.if !empty(PKG_OPTIONS:Mfreetds)
CONFIGURE_ARGS+=	--with-freetds=${BUILDLINK_PREFIX.freetds:Q}
PLIST_SUBST+=	COND_FREETDS=""
.include "../../databases/freetds/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-freetds
PLIST_SUBST+=	COND_FREETDS="@comment "
.endif
