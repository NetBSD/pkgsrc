# $NetBSD: buildlink3.mk,v 1.7 2022/11/23 16:19:00 adam Exp $

BUILDLINK_TREE+=	augeas

.if !defined(AUGEAS_BUILDLINK3_MK)
AUGEAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.augeas+=	augeas>=1.3.0
BUILDLINK_ABI_DEPENDS.augeas?=	augeas>=1.12.0nb6
BUILDLINK_PKGSRCDIR.augeas?=	../../sysutils/augeas

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# AUGEAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-augeas
