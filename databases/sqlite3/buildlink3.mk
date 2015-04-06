# $NetBSD: buildlink3.mk,v 1.16 2015/04/06 08:17:14 adam Exp $

BUILDLINK_TREE+=	sqlite3

.if !defined(SQLITE3_BUILDLINK3_MK)
SQLITE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.0.8
BUILDLINK_ABI_DEPENDS.sqlite3+=	sqlite3>=3.8.8.3nb1
BUILDLINK_PKGSRCDIR.sqlite3?=	../../databases/sqlite3

pkgbase:= sqlite3
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.sqlite3:Micu)
.include "../../textproc/icu/buildlink3.mk"
.endif

.endif # SQLITE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-sqlite3
