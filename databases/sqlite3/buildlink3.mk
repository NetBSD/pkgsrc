# $NetBSD: buildlink3.mk,v 1.35 2023/11/08 13:18:37 wiz Exp $

BUILDLINK_TREE+=	sqlite3

.if !defined(SQLITE3_BUILDLINK3_MK)
SQLITE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.0.8
BUILDLINK_ABI_DEPENDS.sqlite3+=	sqlite3>=3.44.0nb1
BUILDLINK_PKGSRCDIR.sqlite3?=	../../databases/sqlite3

pkgbase:= sqlite3
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.sqlite3:Micu}
.include "../../textproc/icu/buildlink3.mk"
.endif

.endif # SQLITE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-sqlite3
