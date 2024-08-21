# $NetBSD: buildlink3.mk,v 1.1 2024/08/21 21:08:33 nia Exp $

# This buildlink file uses mysql-client and not mariadb-client,
# because some packages depending on it expect BUILDLINK_*.mysql-client
# to be set and will fail build if they get BUILDLINK_*.mariadb-client
# instead.
BUILDLINK_TREE+=	mysql-client

.if !defined(MYSQL_CLIENT_BUILDLINK3_MK)
MYSQL_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mysql-client+=	mariadb-client>=11.4.0<11.5.0
BUILDLINK_ABI_DEPENDS.mysql-client+=	mariadb-client>=11.4.0
BUILDLINK_PKGSRCDIR.mysql-client?=	../../databases/mariadb114-client
BUILDLINK_INCDIRS.mysql-client+=	include/mysql
BUILDLINK_LIBDIRS.mysql-client+=	lib

pkgbase := mysql-client
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.mysql-client:Mssl}
.  include "../../security/openssl/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.endif # MYSQL_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mysql-client
