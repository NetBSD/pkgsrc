# $NetBSD: buildlink3.mk,v 1.12 2025/05/09 19:37:11 wiz Exp $

BUILDLINK_TREE+=	polly

.if !defined(POLLY_BUILDLINK3_MK)
POLLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polly+=	polly>=19.1.0
BUILDLINK_ABI_DEPENDS.polly?=	polly>=19.1.7nb1
BUILDLINK_PKGSRCDIR.polly?=	../../devel/polly

.include "../../lang/llvm/buildlink3.mk"
.endif	# POLLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-polly
