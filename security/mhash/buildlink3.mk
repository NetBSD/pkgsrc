# $NetBSD: buildlink3.mk,v 1.9 2015/03/05 22:31:56 tnn Exp $

BUILDLINK_TREE+=	mhash

.if !defined(MHASH_BUILDLINK3_MK)
MHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mhash+=	mhash>=0.9.9nb6
BUILDLINK_PKGSRCDIR.mhash?=	../../security/mhash
.endif # MHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mhash
