# $NetBSD: buildlink3.mk,v 1.2 2025/01/29 17:25:01 vins Exp $

BUILDLINK_TREE+=	hwdata

.if !defined(HWDATA_BUILDLINK3_MK)
HWDATA_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hwdata?=	build

BUILDLINK_API_DEPENDS.hwdata+=	hwdata>=0.390
BUILDLINK_ABI_DEPENDS.hwdata+=	hwdata>=0.391
BUILDLINK_PKGSRCDIR.hwdata?=	../../sysutils/hwdata
BUILDLINK_FILES.hwdata+=	share/*
.endif	# HWDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hwdata
