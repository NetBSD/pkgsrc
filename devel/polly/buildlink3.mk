# $NetBSD: buildlink3.mk,v 1.10 2024/07/06 15:45:08 adam Exp $

BUILDLINK_TREE+=	polly

.if !defined(POLLY_BUILDLINK3_MK)
POLLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polly+=	polly>=18.0.0
BUILDLINK_PKGSRCDIR.polly?=	../../devel/polly

.include "../../lang/llvm/buildlink3.mk"
.endif	# POLLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-polly
