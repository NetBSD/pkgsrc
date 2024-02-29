# $NetBSD: options.mk,v 1.2 2024/02/29 21:34:33 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensmtpd-extras

PKG_SUPPORTED_OPTIONS+=	ldap mysql perl pgsql python redis sqlite
PKG_SUGGESTED_OPTIONS=	ldap sqlite

PLIST_VARS+=	ldap mysql pgsql python redis sqlite

.include "../../mk/bsd.options.mk"

###
### SQLite based OpenSMTPD table
###
.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-table-sqlite
PLIST.sqlite=       yes
.endif

###
### LDAP based OpenSMTPD table
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-table-ldap
PLIST.ldap=       yes
.endif

###
### MySQL based OpenSMTPD table
###
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-table-mysql
PLIST.mysql=		yes
.endif

###
### PostgreSQL based OpenSMTPD table
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-table-postgres
PLIST.pgsql=		yes
.endif

###
### Redis based OpenSMTPD table
###
.if !empty(PKG_OPTIONS:Mredis)
.  include "../../databases/hiredis/buildlink3.mk"
CONFIGURE_ARGS+=	--with-table-redis
PLIST.redis=		yes
.endif

###
### Perl bindings for OpenSMTPD
###
.if !empty(PKG_OPTIONS:Mperl)
.  include "../../lang/perl5/buildlink3.mk"
USE_TOOLS+=		perl:run
CONFIGURE_ENV+=		need_perl=yes
CONFIGURE_ENV+=		PERL_CONFIG=${PERL5:Q}
CONFIGURE_ARGS+=	--with-perl=${BUILDLINK_PREFIX.perl:Q}
.endif

###
### Python bindings for OpenSMTPD
###
.if !empty(PKG_OPTIONS:Mpython)
# current implementation is incompatible and does not build with python3
PYTHON_VERSIONS_ACCEPTED=	27
.  include "../../converters/libiconv/buildlink3.mk"
.  include "../../devel/gettext-lib/buildlink3.mk"
.  include "../../lang/python/application.mk"
CONFIGURE_ARGS+=	--with-python=${PREFIX:Q}
CONFIGURE_ARGS+=	--with-python-type=python${PYVERSSUFFIX}
CONFIGURE_ARGS+=	--with-queue-python
CONFIGURE_ARGS+=	--with-scheduler-python
PLIST.python=		yes
.endif
