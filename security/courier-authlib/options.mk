# $NetBSD: options.mk,v 1.1.1.1 2005/02/10 03:21:31 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.courier-authlib
PKG_SUPPORTED_OPTIONS=	PAM bdb ldap mysql pgsql

.if !defined(PKG_OPTIONS.courier-auth)
PKG_DEFAULT_OPTIONS+=	bdb
.endif
.include "../../mk/bsd.options.mk"

###
### UNIX (shadow) password authentication
###
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthpwd.la
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthshadow.la

###
### PAM authentication
###
.if !empty(PKG_OPTIONS:MPAM)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-authpam
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthpam.la
.else
CONFIGURE_ARGS+=	--without-authpam
.endif

###
### Berkeley DB password authentication
###
.if !empty(PKG_OPTIONS:Mbdb)
USE_DB185=		yes
.  include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-db=db
CONFIGURE_ARGS+=	--with-authuserdb
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthuserdb.la
AUTHLIB_PLIST+=		${AUTHLIBEXECDIR}/makedatprog
AUTHLIB_PLIST+=		sbin/vchkpw2userdb
AUTHLIB_PLIST+=		sbin/pw2userdb
AUTHLIB_PLIST+=		sbin/makeuserdb
AUTHLIB_PLIST+=		sbin/userdb
AUTHLIB_PLIST+=		sbin/userdbpw
AUTHLIB_PLIST+=		sbin/userdb-test-cram-md5
.else
CONFIGURE_ARGS+=	--without-authuserdb
PLIST_SUBST+=		BDB="@comment "
.endif

###
### LDAP authentication
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-authldap
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthldap.la
AUTHLIB_PLIST+=		${AUTHEXAMPLEDIR}/authldaprc.dist
AUTHLIB_PLIST+=		${AUTHEXAMPLEDIR}/authldap.schema
GEN_FILES+=		authldaprc
.else
CONFIGURE_ARGS+=	--without-authldap
.endif

###
### MySQL authentication
###
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../databases/mysql4-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-authmysql
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthmysql.la
AUTHLIB_PLIST+=		${AUTHEXAMPLEDIR}/authmysqlrc.dist
GEN_FILES+=		authmysqlrc
.else
CONFIGURE_ARGS+=	--without-authmysql
.endif

###
### PostgreSQL authentication
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-authpgsql
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthpgsql.la
AUTHLIB_PLIST+=		${AUTHEXAMPLEDIR}/authpgsqlrc.dist
GEN_FILES+=		authpgsqlrc
.else
CONFIGURE_ARGS+=	--without-authpgsql
.endif

###
### We never build the following modules (unsupported by author).
###
CONFIGURE_ARGS+=	--without-authvchkpw
CONFIGURE_ARGS+=	--without-authcustom
