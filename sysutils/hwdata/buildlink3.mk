# $NetBSD: buildlink3.mk,v 1.3 2025/02/13 13:26:13 vins Exp $

BUILDLINK_TREE+=	hwdata

.if !defined(HWDATA_BUILDLINK3_MK)
HWDATA_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hwdata?=	build

BUILDLINK_API_DEPENDS.hwdata+=	hwdata>=0.391nb1
BUILDLINK_ABI_DEPENDS.hwdata+=	hwdata>=0.391nb1
BUILDLINK_PKGSRCDIR.hwdata?=	../../sysutils/hwdata
BUILDLINK_FILES.hwdata+=	share/hwdata/*.ids
.endif	# HWDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hwdata
