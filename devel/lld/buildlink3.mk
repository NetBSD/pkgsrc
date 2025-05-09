# $NetBSD: buildlink3.mk,v 1.10 2025/05/09 19:37:11 wiz Exp $

BUILDLINK_TREE+=	lld

.if !defined(LLD_BUILDLINK3_MK)
LLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lld+=	lld>=19.1.0
BUILDLINK_ABI_DEPENDS.lld?=	lld>=19.1.7nb1
BUILDLINK_PKGSRCDIR.lld?=	../../devel/lld

.include "../../lang/llvm/buildlink3.mk"
.endif	# LLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-lld
