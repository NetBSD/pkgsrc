# $NetBSD: buildlink3.mk,v 1.6 2023/10/06 19:15:19 adam Exp $

BUILDLINK_TREE+=	lld

.if !defined(LLD_BUILDLINK3_MK)
LLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lld+=	lld>=16.0.0<17
BUILDLINK_PKGSRCDIR.lld?=	../../devel/lld

.include "../../lang/llvm/buildlink3.mk"
.endif	# LLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-lld
