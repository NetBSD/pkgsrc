# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:20 joerg Exp $

BUILDLINK_TREE+=	mhash

.if !defined(MHASH_BUILDLINK3_MK)
MHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mhash+=	mhash>=0.8.3
BUILDLINK_ABI_DEPENDS.mhash+=	mhash>=0.9.2nb1
BUILDLINK_PKGSRCDIR.mhash?=	../../security/mhash
.endif # MHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-mhash
