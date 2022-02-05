# $NetBSD: buildlink3.mk,v 1.1 2022/02/05 03:09:26 ryoon Exp $

BUILDLINK_TREE+=	libtpms

.if !defined(LIBTPMS_BUILDLINK3_MK)
LIBTPMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtpms+=	libtpms>=0.9.0
BUILDLINK_PKGSRCDIR.libtpms?=	../../sysutils/libtpms

.endif	# LIBTPMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtpms
