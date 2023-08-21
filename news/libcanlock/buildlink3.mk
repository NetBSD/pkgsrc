# $NetBSD: buildlink3.mk,v 1.2 2023/08/21 13:29:44 micha Exp $

BUILDLINK_TREE+=	libcanlock

.if !defined(LIBCANLOCK_BUILDLINK3_MK)
LIBCANLOCK_BUILDLINK3_MK:=

USE_CC_FEATURES+=	c99

BUILDLINK_API_DEPENDS.libcanlock+=	libcanlock>=3.0.0
BUILDLINK_PKGSRCDIR.libcanlock?=	../../news/libcanlock
.endif	# LIBCANLOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcanlock
