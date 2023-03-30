# $NetBSD: buildlink3.mk,v 1.1 2023/03/30 13:50:20 ryoon Exp $

BUILDLINK_TREE+=	dtc

.if !defined(DTC_BUILDLINK3_MK)
DTC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dtc+=	dtc>=1.7.0
BUILDLINK_PKGSRCDIR.dtc?=	../../sysutils/dtc
.endif	# DTC_BUILDLINK3_MK

BUILDLINK_TREE+=	-dtc
