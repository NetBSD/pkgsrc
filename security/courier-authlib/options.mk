# $NetBSD: options.mk,v 1.11 2008/02/18 20:26:33 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.courier-authlib
PKG_SUPPORTED_OPTIONS=	pam bdb ldap mysql pgsql
PKG_SUGGESTED_OPTIONS=	bdb

.include "../../mk/bsd.options.mk"

###
### UNIX (shadow) password authentication
###
CONFIGURE_ARGS+=	--with-authpwd
CONFIGURE_ARGS+=	--with-authshadow
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthpwd.la
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthshadow.la

###
### "pipe-to-external-program" authentication
###
CONFIGURE_ARGS+=	--with-authpipe
REPLACE_PERL+=		samplepipe.pl
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthpipe.la
AUTHLIB_PLIST+=		${AUTHEXAMPLEDIR}/samplepipe.pl
POST_INSTALL_TARGETS+=	post-install-pipe

post-install-pipe:
	${INSTALL_SCRIPT} ${WRKSRC}/samplepipe.pl ${DESTDIR}${EGDIR}

###
### PAM authentication
###
.if !empty(PKG_OPTIONS:Mpam)
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
AUTHLIB_PLIST+=		sbin/makeuserdb
AUTHLIB_PLIST+=		sbin/pw2userdb
AUTHLIB_PLIST+=		sbin/userdb
AUTHLIB_PLIST+=		sbin/userdb-test-cram-md5
AUTHLIB_PLIST+=		sbin/userdbpw
AUTHLIB_PLIST+=		sbin/vchkpw2userdb
.else
CONFIGURE_ARGS+=	--without-authuserdb
PLIST_SUBST+=		BDB="@comment "
.endif

###
### LDAP authentication
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-authldap
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthldap.la
AUTHLIB_PLIST+=		${AUTHEXAMPLEDIR}/authldaprc.dist
AUTHLIB_PLIST+=		${AUTHEXAMPLEDIR}/authldap.schema
AUTHLIB_PLIST+=		${AUTHDOCDIR}/README.ldap
GEN_FILES+=		authldaprc
POST_INSTALL_TARGETS+=	post-install-ldap

post-install-ldap:
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${EGDIR}/authldaprc.dist
	${CHMOD} ${SHAREMODE} ${DESTDIR}${EGDIR}/authldaprc.dist
	${INSTALL_DATA} ${WRKSRC}/README.ldap ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/authldap.schema ${DESTDIR}${EGDIR}
.else
CONFIGURE_ARGS+=	--without-authldap
.endif

###
### MySQL authentication
###
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-authmysql
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthmysql.la
AUTHLIB_PLIST+=		${AUTHEXAMPLEDIR}/authmysqlrc.dist
AUTHLIB_PLIST+=		${AUTHDOCDIR}/README.authmysql.html
GEN_FILES+=		authmysqlrc
POST_INSTALL_TARGETS+=	post-install-mysql

post-install-mysql:
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${EGDIR}/authmysqlrc.dist
	${CHMOD} ${SHAREMODE} ${DESTDIR}${EGDIR}/authmysqlrc.dist
	${INSTALL_DATA} ${WRKSRC}/README.authmysql.html ${DESTDIR}${DOCDIR}
.else
CONFIGURE_ARGS+=	--without-authmysql
.endif

###
### PostgreSQL authentication
###
.if !empty(PKG_OPTIONS:Mpgsql)
#
# Prevent auto-adding gettext libraries to LIBS -- we only want them
# used when we link with -lpq.
#
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-authpgsql
CONFIGURE_ENV+=		PGSQL_LIBS="${BUILDLINK_LDADD.${PGSQL_TYPE}}"
AUTHLIB_PLIST+=		${AUTHLIBDIR}/libauthpgsql.la
AUTHLIB_PLIST+=		${AUTHEXAMPLEDIR}/authpgsqlrc.dist
AUTHLIB_PLIST+=		${AUTHDOCDIR}/README.authpostgres.html
GEN_FILES+=		authpgsqlrc
POST_INSTALL_TARGETS+=	post-install-pgsql

post-install-pgsql:
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${EGDIR}/authpgsqlrc.dist
	${CHMOD} ${SHAREMODE} ${DESTDIR}${EGDIR}/authpgsqlrc.dist
	${INSTALL_DATA} ${WRKSRC}/README.authpostgres.html ${DESTDIR}${DOCDIR}
.else
CONFIGURE_ARGS+=	--without-authpgsql
.endif

###
### We never build the following modules (unsupported by author).
###
CONFIGURE_ARGS+=	--without-authvchkpw
CONFIGURE_ARGS+=	--without-authcustom
