# $NetBSD: options.mk,v 1.5 2007/12/22 21:13:46 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.teapop
PKG_SUPPORTED_OPTIONS=	drac mysql apop vpop tcpd pgsql ldap inet6
PKG_SUGGESTED_OPTIONS=	apop vpop tcpd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdrac)
.  include "../../mail/drac/buildlink3.mk"
CONFIGURE_ARGS+=	--with-drac=${BUILDLINK_PREFIX.drac}/lib
CONFIGURE_ARGS+=	--with-dracinc=${BUILDLINK_PREFIX.drac}/include
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
LDFLAGS+=		${BUILDLINK_LDFLAGS.mysql-client}
.endif

.if !empty(PKG_OPTIONS:Mapop)
CONFIGURE_ARGS+=	--enable-apop
.else
CONFIGURE_ARGS+=	--disable-apop
.endif

.if !empty(PKG_OPTIONS:Mvpop)
CONFIGURE_ARGS+=	--enable-vpop
.else
CONFIGURE_ARGS+=	--disable-vpop
.endif

.if !empty(PKG_OPTIONS:Mtcpd)
.  include "../../security/tcp_wrappers/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tcpd
.else
CONFIGURE_ARGS+=	--without-tcpd
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
LDFLAGS+=		${BUILDLINK_LDFLAGS.postgresql-lib}
.endif

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=openldap
CONFIGURE_ARGS+=	--with-ldapinc=${BUILDLINK_PREFIX.openldap-client}/include
CONFIGURE_ARGS+=	--with-ldaplib=${BUILDLINK_PREFIX.openldap-client}/lib
LDFLAGS+=		${BUILDLINK_LDFLAGS.openldap-client}
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
