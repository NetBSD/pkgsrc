# $NetBSD: buildlink3.mk,v 1.16 2026/10/11 16:02:18 wiz Exp $

BUILDLINK_TREE+=	polly

.if !defined(POLLY_BUILDLINK3_MK)
POLLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polly+=	polly>=22.1.0
BUILDLINK_ABI_DEPENDS.polly?=	polly>=22.1.8nb1
BUILDLINK_PKGSRCDIR.polly?=	../../devel/polly

.include "../../lang/llvm/buildlink3.mk"
.endif	# POLLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-polly
