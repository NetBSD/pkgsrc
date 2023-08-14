# $NetBSD: buildlink3.mk,v 1.5 2023/08/14 05:24:12 wiz Exp $

BUILDLINK_TREE+=	lld

.if !defined(LLD_BUILDLINK3_MK)
LLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lld+=	lld>=9.0.1<16
BUILDLINK_ABI_DEPENDS.lld?=	lld>=15.0.7nb2
BUILDLINK_PKGSRCDIR.lld?=	../../devel/lld

.include "../../lang/llvm/buildlink3.mk"
.endif	# LLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-lld
