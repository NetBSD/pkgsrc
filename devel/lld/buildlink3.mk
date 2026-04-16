# $NetBSD: buildlink3.mk,v 1.12 2026/04/16 06:33:49 wiz Exp $

BUILDLINK_TREE+=	lld

.if !defined(LLD_BUILDLINK3_MK)
LLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lld+=	lld>=21.1.0
BUILDLINK_PKGSRCDIR.lld?=	../../devel/lld

.include "../../lang/llvm/buildlink3.mk"
.endif	# LLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-lld
