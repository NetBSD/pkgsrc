# $NetBSD: buildlink3.mk,v 1.35 2026/02/06 10:04:56 wiz Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

# Proj withdrew the old API with 8.0.0.
BUILDLINK_API_DEPENDS.proj+=	proj>=8.0.0
BUILDLINK_ABI_DEPENDS.proj+=	proj>=9.7.1nb2
BUILDLINK_PKGSRCDIR.proj?=	../../geography/proj

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
