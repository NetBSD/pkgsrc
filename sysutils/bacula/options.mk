# $NetBSD: options.mk,v 1.16 2010/03/11 16:03:49 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bacula
PKG_SUPPORTED_OPTIONS=		bacula-static ssl python
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	catalog-sqlite3 catalog-pgsql catalog-mysql
PKG_SUGGESTED_OPTIONS=		catalog-sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcatalog-sqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
BACULA_DB=		sqlite3
.elif !empty(PKG_OPTIONS:Mcatalog-pgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX}
BACULA_DB=		postgresql
.elif !empty(PKG_OPTIONS:Mcatalog-mysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
BACULA_DB=		mysql
.endif

.if !empty(PKG_OPTIONS:Mpython)
.  include "../../lang/python/application.mk"
.  include "${PYPKGSRCDIR}/buildlink3.mk"
CONFIGURE_ARGS+=	--with-python=${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYINC}
# we can't use REPLACE_INTERPRETER here because ./configure fills in the
# python path and the replace-interpreter stage happens before that.
SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fixing Python interpreter path.
SUBST_STAGE.python=	post-configure
SUBST_FILES.python=	scripts/dvd-handler
SUBST_SED.python=	-e '1s,^\#!.*,\#! ${PYTHONBIN},'
.endif

.if !empty(PKG_OPTIONS:Mbacula-static)
CONFIGURE_ARGS+=	--enable-static-cons
CONFIGURE_ARGS+=	--enable-static-dir
CONFIGURE_ARGS+=	--enable-static-fd
CONFIGURE_ARGS+=	--enable-static-sd
CONFIGURE_ARGS+=	--enable-static-tools
PLIST_SUBST+=		STATIC=
.else
PLIST_SUBST+=		STATIC="@comment "
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.endif
