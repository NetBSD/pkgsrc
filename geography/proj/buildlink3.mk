# $NetBSD: buildlink3.mk,v 1.14 2023/01/03 17:36:22 wiz Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.proj+=	proj>=5.0.0
BUILDLINK_ABI_DEPENDS.proj+=	proj>=7.2.1nb2
BUILDLINK_PKGSRCDIR.proj?=	../../geography/proj
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
