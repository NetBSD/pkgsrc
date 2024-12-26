# $NetBSD: buildlink3.mk,v 1.1 2024/12/26 18:33:23 bsiegert Exp $

BUILDLINK_TREE+=	hwdata

.if !defined(HWDATA_BUILDLINK3_MK)
HWDATA_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hwdata?=	build

BUILDLINK_API_DEPENDS.hwdata+=	hwdata>=0.390
BUILDLINK_PKGSRCDIR.hwdata?=	../../sysutils/hwdata
.endif	# HWDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hwdata
