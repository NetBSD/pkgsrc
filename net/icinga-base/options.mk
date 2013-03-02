# $NetBSD: options.mk,v 1.1 2013/03/02 04:08:27 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.icinga-base
PKG_SUPPORTED_OPTIONS=	mysql pgsql
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
