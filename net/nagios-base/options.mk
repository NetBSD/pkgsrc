# $NetBSD: options.mk,v 1.1.1.1 2006/02/18 17:12:20 bouyer Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nagios-base
PKG_SUPPORTED_OPTIONS=	mysql pgsql
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql-lib=${LOCALBASE}/lib/mysql		\
			--with-mysql-inc=${LOCALBASE}/include/mysql	\
			--with-mysql-xdata
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql-lib=${LOCALBASE}/pgsql \
			--with-pgsql-inc=${LOCALBASE}/pgsql \
			--with-pgsql-xdata
.include "../../mk/pgsql.buildlink3.mk"
.endif
