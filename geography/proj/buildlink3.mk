# $NetBSD: buildlink3.mk,v 1.25 2024/09/01 22:28:58 gdt Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

# Proj withdrew the old API with 8.0.0.
BUILDLINK_API_DEPENDS.proj+=	proj>=8.0.0
BUILDLINK_ABI_DEPENDS.proj+=	proj>=9.4.1
BUILDLINK_PKGSRCDIR.proj?=	../../geography/proj

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
