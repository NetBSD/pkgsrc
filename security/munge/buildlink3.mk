# $NetBSD: buildlink3.mk,v 1.3 2024/05/14 21:00:27 bacon Exp $

BUILDLINK_TREE+=	munge

.if !defined(MUNGE_BUILDLINK3_MK)
MUNGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.munge+=	munge>=0.5.16
BUILDLINK_PKGSRCDIR.munge?=	../../security/munge

.endif	# MUNGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-munge
