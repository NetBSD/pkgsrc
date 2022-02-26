# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:03 pho Exp $

BUILDLINK_TREE+=	hs-optparse-simple

.if !defined(HS_OPTPARSE_SIMPLE_BUILDLINK3_MK)
HS_OPTPARSE_SIMPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-optparse-simple+=	hs-optparse-simple>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-optparse-simple+=	hs-optparse-simple>=0.1.1.4nb1
BUILDLINK_PKGSRCDIR.hs-optparse-simple?=	../../devel/hs-optparse-simple

.include "../../devel/hs-githash/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-th-compat/buildlink3.mk"
.endif	# HS_OPTPARSE_SIMPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-optparse-simple
