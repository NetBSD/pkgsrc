# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:31 rillig Exp $

BUILDLINK_TREE+=	augeas

.if !defined(AUGEAS_BUILDLINK3_MK)
AUGEAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.augeas+=	augeas>=1.3.0
BUILDLINK_PKGSRCDIR.augeas?=	../../sysutils/augeas

.include "../../textproc/libxml2/buildlink3.mk"
.endif	# AUGEAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-augeas
