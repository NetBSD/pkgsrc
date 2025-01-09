# $NetBSD: buildlink3.mk,v 1.3 2025/01/09 23:15:15 wiz Exp $

BUILDLINK_TREE+=	hs-djot

.if !defined(HS_DJOT_BUILDLINK3_MK)
HS_DJOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-djot+=	hs-djot>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-djot+=	hs-djot>=0.1.1.3nb2
BUILDLINK_PKGSRCDIR.hs-djot?=	../../textproc/hs-djot

.include "../../textproc/hs-doclayout/buildlink3.mk"
.endif	# HS_DJOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-djot
