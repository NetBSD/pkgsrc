# $NetBSD: options.mk,v 1.4 2010/05/27 10:49:07 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sysbench
PKG_SUPPORTED_OPTIONS+= mysql pgsql doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.  include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX}
.  include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if !empty(PKG_OPTIONS:Mdoc)
.  include "../../textproc/libxslt/buildlink3.mk"
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
.endif
