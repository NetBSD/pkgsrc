# $NetBSD: options.mk,v 1.1 2009/08/24 13:50:03 hasso Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libpreludedb
PKG_SUPPORTED_OPTIONS=		perl python
PKG_OPTIONS_NONEMPTY_SETS=	database
PKG_OPTIONS_SET.database=	mysql pgsql sqlite3

# hmmmm, maybe the user should be forced to select?
PKG_SUGGESTED_OPTIONS=		sqlite3

.include "../../mk/bsd.options.mk"

###
### python is needed for prewikka
###

PLIST_VARS+=		python mysql pgsql sqlite3
.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q} --with-perl-installdirs=vendor
USE_TOOLS+=		perl:run

PERL5_PACKLIST=		${PERL5_VENDORARCH}auto/PreludeDB/.packlist
PERL5_CONFIGURE=	no
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
PYBINMODULE=		yes
PLIST.python=		yes
PY_PATCHPLIST=		yes
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--with-python=no
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config

PLIST.mysql=		yes
.include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX}/bin/pg_config

PLIST.pgsql=		yes
.include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-postgresql=no
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}

PLIST.sqlite3=		yes
.include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-sqlite3=no
.endif
