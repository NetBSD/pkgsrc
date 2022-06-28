# $NetBSD: buildlink3.mk,v 1.10 2022/06/28 11:35:38 wiz Exp $

BUILDLINK_TREE+=	mhash

.if !defined(MHASH_BUILDLINK3_MK)
MHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mhash+=	mhash>=0.9.9nb6
BUILDLINK_ABI_DEPENDS.mhash?=	mhash>=0.9.9nb13
BUILDLINK_PKGSRCDIR.mhash?=	../../security/mhash
.endif # MHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mhash
