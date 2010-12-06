# $NetBSD: options.mk,v 1.6 2010/12/06 11:56:44 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.koffice
PKG_SUPPORTED_OPTIONS=	mysql pgsql koffice-wv2 koffice-libwpd
PKG_SUGGESTED_OPTIONS=	koffice-wv2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		libwpd mysql pgsql wv2

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
PLIST.mysql=		yes
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/libpqxx/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql-includes=${PGSQL_PREFIX}/include
CONFIGURE_ARGS+=	--with-pgsql-libraries=${PGSQL_PREFIX}/lib
CONFIGURE_ARGS+=	--with-pqxx-includes=${BUILDLINK_PREFIX.libpqxx}/include
CONFIGURE_ARGS+=	--with-pqxx-libraries=${BUILDLINK_PREFIX.libpqxx}/lib
PLIST.pgsql=		yes
.else
CONFIGURE_ARGS+=	--disable-pgsql
.endif

.if !empty(PKG_OPTIONS:Mkoffice-wv2)
.include "../../converters/wv2/buildlink3.mk"
PLIST.wv2=		yes
.else
CONFIGURE_ARGS+=	--without-libwv2
.endif

.if !empty(PKG_OPTIONS:Mkoffice-libwpd)
.include "../../converters/libwpd/buildlink3.mk"
PLIST.libwpd=		yes
.endif
