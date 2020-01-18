# $NetBSD: buildlink3.mk,v 1.13 2020/01/18 21:47:59 jperkin Exp $

BUILDLINK_TREE+=	libzdb

.if !defined(LIBZDB_BUILDLINK3_MK)
LIBZDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzdb+=	libzdb>=2.6
BUILDLINK_ABI_DEPENDS.libzdb?=	libzdb>=3.1nb13
BUILDLINK_PKGSRCDIR.libzdb?=	../../databases/libzdb

pkgbase := libzdb
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libzdb:Msqlite)
.  include "../../databases/sqlite3/buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libzdb:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libzdb:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.libzdb:Mssl)
.  include "../../security/openssl/buildlink3.mk"
.endif

.endif	# LIBZDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzdb
