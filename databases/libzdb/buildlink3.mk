# $NetBSD: buildlink3.mk,v 1.30 2026/01/07 08:46:10 wiz Exp $

BUILDLINK_TREE+=	libzdb

.if !defined(LIBZDB_BUILDLINK3_MK)
LIBZDB_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

BUILDLINK_API_DEPENDS.libzdb+=	libzdb>=2.6
BUILDLINK_ABI_DEPENDS.libzdb+=	libzdb>=3.5.0nb1
BUILDLINK_PKGSRCDIR.libzdb?=	../../databases/libzdb

pkgbase := libzdb
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.libzdb:Msqlite}
.  include "../../databases/sqlite3/buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libzdb:Mpgsql}
.  include "../../mk/pgsql.buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libzdb:Mmysql}
.  include "../../mk/mysql.buildlink3.mk"
.endif
.if ${PKG_BUILD_OPTIONS.libzdb:Mssl}
.  include "../../security/openssl/buildlink3.mk"
.endif

.endif	# LIBZDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzdb
