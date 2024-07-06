# $NetBSD: buildlink3.mk,v 1.8 2024/07/06 15:45:08 adam Exp $

BUILDLINK_TREE+=	lld

.if !defined(LLD_BUILDLINK3_MK)
LLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lld+=	lld>=18.0.0
BUILDLINK_PKGSRCDIR.lld?=	../../devel/lld

.include "../../lang/llvm/buildlink3.mk"
.endif	# LLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-lld
