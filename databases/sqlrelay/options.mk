# $NetBSD: options.mk,v 1.7 2011/11/02 13:59:29 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sqlrelay
PKG_SUPPORTED_OPTIONS+= mysql pgsql sqlite odbc freetds perl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		freetds mysql odbc perl pgsql sqlite

.if !empty(PKG_OPTIONS:Mperl)
LICENSE+=		AND artistic
PERL5_PACKLIST=		auto/SQLRelay/Connection/.packlist
PERL5_PACKLIST+=	auto/SQLRelay/Cursor/.packlist
PERL5_PACKLIST+=	auto/DBD/SQLRelay/.packlist

CONFIGURE_ARGS+=	--with-perl-site-arch=${PERL5_INSTALLVENDORARCH:Q}
CONFIGURE_ARGS+=	--with-perl-site-lib=${PERL5_INSTALLVENDORLIB:Q}
CONFIGURE_ARGS+=	--with-perl-install-man3-dir=${PERL5_INSTALLVENDORMAN3DIR:Q}

USE_TOOLS+=		perl
PLIST.perl=		yes

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/packlist.mk"
.include "../../lang/perl5/vars.mk"

.else
CONFIGURE_ARGS+=	--disable-perl
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql-prefix=${BUILDLINK_PREFIX.mysql-client:Q}
PLIST.mysql=		yes
.include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
LICENSE+=		AND postgresql-license
CONFIGURE_ARGS+=	--with-postgresql-prefix=${PGSQL_PREFIX:Q}
PLIST.pgsql=		yes
.include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-postgresql
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=	--with-sqlite-prefix=${BUILDLINK_PREFIX.sqlite3:Q}
PLIST.sqlite=		yes
.include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sqlite
.endif

.if !empty(PKG_OPTIONS:Modbc)
CONFIGURE_ARGS+=	--with-odbc-prefix=${BUILDLINK_PREFIX.unixodbc:Q}
PLIST.odbc=		yes
.include "../../databases/unixodbc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-odbc
.endif

.if !empty(PKG_OPTIONS:Mfreetds)
CONFIGURE_ARGS+=	--with-freetds-prefix=${BUILDLINK_PREFIX.freetds:Q}
PLIST.freetds=		yes
.include "../../databases/freetds/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-freetds
.endif
