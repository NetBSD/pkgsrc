# $NetBSD: options.mk,v 1.1 2004/11/25 20:49:30 xtraeme Exp $
#
# XXX Support for the following variables will be removed after the
# XXX pkgsrc-2004Q4 branch is released:
# XXX
# XXX POP_WITH_DRAC
# XXX TEAPOP_WITH_MYSQL
# XXX TEAPOP_WITHOUT_APOP
# XXX TEAPOP_WITHOUT_VPOP

.if defined(POP_WITH_DRAC) && !empty(POP_WITH_DRAC:M[Yy][Ee][Ss])
PKG_SUPPORTED_OPTIONS+=	drac
.endif

.if defined(TEAPOP_WITH_MYSQL) && !empty(TEAPOP_WITH_MYSQL:M[Yy][Ee][Ss])
PKG_SUPPORTED_OPTIONS+=	mysql
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.teapop
PKG_SUPPORTED_OPTIONS=	drac mysql apop vpop tcpd pgsql ldap inet6
PKG_DEFAULT_OPTIONS+=	apop vpop tcpd

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
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=openldap
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
LDFLAGS+=		${BUILDLINK_LDFLAGS.openldap}
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

