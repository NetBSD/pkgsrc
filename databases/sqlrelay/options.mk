# $NetBSD: options.mk,v 1.6 2008/04/12 22:42:59 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sqlrelay
PKG_SUPPORTED_OPTIONS+= mysql pgsql sqlite odbc freetds perl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		freetds mysql odbc perl pgsql sqlite

.if !empty(PKG_OPTIONS:Mperl)
PERL5_PACKLIST=		auto/SQLRelay/Connection/.packlist
PERL5_PACKLIST+=	auto/SQLRelay/Cursor/.packlist
PERL5_PACKLIST+=	auto/DBD/SQLRelay/.packlist

CONFIGURE_ARGS+=	--with-perl-site-arch=${PERL5_INSTALLVENDORARCH:Q}
CONFIGURE_ARGS+=	--with-perl-site-lib=${PERL5_INSTALLVENDORLIB:Q}
CONFIGURE_ARGS+=	--with-perl-install-man3-dir=${PERL5_INSTALLVENDORMAN3DIR:Q}

PLIST.perl=		yes

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/packlist.mk"
.include "../../lang/perl5/vars.mk"

.else
CONFIGURE_ARGS+=	--disable-perl
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client:Q}
PLIST.mysql=		yes
.include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX:Q}
PLIST.pgsql=		yes
.include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-postgresql
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite3:Q}
PLIST.sqlite=		yes
.include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sqlite
.endif

.if !empty(PKG_OPTIONS:Modbc)
CONFIGURE_ARGS+=	--with-odbc=${BUILDLINK_PREFIX.unixodbc:Q}
PLIST.odbc=		yes
.include "../../databases/unixodbc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-odbc
.endif

.if !empty(PKG_OPTIONS:Mfreetds)
CONFIGURE_ARGS+=	--with-freetds=${BUILDLINK_PREFIX.freetds:Q}
PLIST.freetds=		yes
.include "../../databases/freetds/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-freetds
.endif
