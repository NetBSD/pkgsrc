# $NetBSD: buildlink3.mk,v 1.5 2020/03/15 21:41:27 tnn Exp $

BUILDLINK_TREE+=	proj

.if !defined(PROJ_BUILDLINK3_MK)
PROJ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.proj+=	proj>=5.0.0
BUILDLINK_ABI_DEPENDS.proj+=	proj>=5.0.0
BUILDLINK_PKGSRCDIR.proj?=	../../geography/proj
.include "../../databases/sqlite3/buildlink3.mk"
.endif # PROJ_BUILDLINK3_MK

BUILDLINK_TREE+=	-proj
