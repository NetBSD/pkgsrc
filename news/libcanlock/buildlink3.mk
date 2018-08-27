# $NetBSD: buildlink3.mk,v 1.1 2018/08/27 15:14:03 wiz Exp $

BUILDLINK_TREE+=	libcanlock

.if !defined(LIBCANLOCK_BUILDLINK3_MK)
LIBCANLOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcanlock+=	libcanlock>=3.0.0
BUILDLINK_PKGSRCDIR.libcanlock?=	../../news/libcanlock
.endif	# LIBCANLOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcanlock
