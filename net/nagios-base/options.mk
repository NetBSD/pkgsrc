# $NetBSD: options.mk,v 1.3 2023/03/17 11:51:34 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nagios-base
PKG_SUPPORTED_OPTIONS=	mysql pgsql ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql-lib=${PREFIX}/lib/mysql		\
			--with-mysql-inc=${PREFIX}/include/mysql	\
			--with-mysql-xdata
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql-lib=${PREFIX}/pgsql \
			--with-pgsql-inc=${PREFIX}/pgsql \
			--with-pgsql-xdata
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if ${PKG_OPTIONS:Mssl}
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif
