# $NetBSD: buildlink3.mk,v 1.13 2023/02/07 01:40:30 pho Exp $

BUILDLINK_TREE+=	hs-cmdargs

.if !defined(HS_CMDARGS_BUILDLINK3_MK)
HS_CMDARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.20
BUILDLINK_ABI_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.21nb5
BUILDLINK_PKGSRCDIR.hs-cmdargs?=	../../devel/hs-cmdargs
.endif	# HS_CMDARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmdargs
