# $NetBSD: buildlink3.mk,v 1.11 2022/11/23 16:18:46 adam Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.proj+=	proj>=5.0.0
BUILDLINK_ABI_DEPENDS.proj+=	proj>=6.3.2nb6
BUILDLINK_PKGSRCDIR.proj?=	../../geography/proj
.include "../../databases/sqlite3/buildlink3.mk"
.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
