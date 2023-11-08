# $NetBSD: buildlink3.mk,v 1.9 2023/11/08 13:20:52 wiz Exp $

BUILDLINK_TREE+=	augeas

.if !defined(AUGEAS_BUILDLINK3_MK)
AUGEAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.augeas+=	augeas>=1.3.0
BUILDLINK_ABI_DEPENDS.augeas?=	augeas>=1.12.0nb8
BUILDLINK_PKGSRCDIR.augeas?=	../../sysutils/augeas

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# AUGEAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-augeas
