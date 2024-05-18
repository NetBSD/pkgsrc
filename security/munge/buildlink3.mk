# $NetBSD: buildlink3.mk,v 1.4 2024/05/18 22:31:05 bacon Exp $

BUILDLINK_TREE+=	munge

.if !defined(MUNGE_BUILDLINK3_MK)
MUNGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.munge+=	munge>=0.5.10
BUILDLINK_PKGSRCDIR.munge?=	../../security/munge

.endif	# MUNGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-munge
