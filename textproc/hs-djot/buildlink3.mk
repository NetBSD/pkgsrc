# $NetBSD: buildlink3.mk,v 1.1 2024/05/04 11:45:51 pho Exp $

BUILDLINK_TREE+=	hs-djot

.if !defined(HS_DJOT_BUILDLINK3_MK)
HS_DJOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-djot+=	hs-djot>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-djot+=	hs-djot>=0.1.1.3
BUILDLINK_PKGSRCDIR.hs-djot?=	../../textproc/hs-djot

.include "../../textproc/hs-doclayout/buildlink3.mk"
.endif	# HS_DJOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-djot
