# $NetBSD: buildlink3.mk,v 1.1 2014/12/30 08:45:49 plunky Exp $

BUILDLINK_TREE+=	libnova

.if !defined(LIBNOVA_BUILDLINK3_MK)
LIBNOVA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnova+=	libnova>=0.13.0
BUILDLINK_ABI_DEPENDS.libnova+=	libnova>=0.13.0
BUILDLINK_PKGSRCDIR.libnova?=	../../geography/libnova
.endif	# LIBNOVA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnova
