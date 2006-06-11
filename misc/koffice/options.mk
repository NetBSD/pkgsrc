# $NetBSD: options.mk,v 1.3 2006/06/11 13:50:19 markd Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.koffice
PKG_SUPPORTED_OPTIONS=  mysql pgsql koffice-wv2 koffice-libwpd
PKG_SUGGESTED_OPTIONS=	koffice-wv2 koffice-libwpd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
PLIST_SUBST+=		HAVE_MYSQL=
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUBST+=		HAVE_MYSQL="@comment "
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/libpqxx/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql-includes=${PGSQL_PREFIX}/include
CONFIGURE_ARGS+=	--with-pgsql-libraries=${PGSQL_PREFIX}/lib
CONFIGURE_ARGS+=	--with-pqxx-includes=${BUILDLINK_PREFIX.libpqxx}/include
CONFIGURE_ARGS+=	--with-pqxx-libraries=${BUILDLINK_PREFIX.libpqxx}/lib
PLIST_SUBST+=		HAVE_PGSQL=
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUBST+=		HAVE_PGSQL="@comment "
.endif

.if !empty(PKG_OPTIONS:Mkoffice-wv2)
.include "../../converters/wv2/buildlink3.mk"
PLIST_SUBST+=		HAVE_WV2=
.else
CONFIGURE_ARGS+=	--without-libwv2
PLIST_SUBST+=		HAVE_WV2="@comment "
.endif

.if !empty(PKG_OPTIONS:Mkoffice-libwpd)
.include "../../converters/libwpd/buildlink3.mk"
PLIST_SUBST+=		HAVE_WPD=
.else
PLIST_SUBST+=		HAVE_WPD="@comment "
.endif
