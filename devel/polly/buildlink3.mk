# $NetBSD: buildlink3.mk,v 1.3 2017/07/11 19:47:37 adam Exp $

BUILDLINK_TREE+=	polly

.if !defined(POLLY_BUILDLINK3_MK)
POLLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polly+=	polly>=4.0.1
BUILDLINK_PKGSRCDIR.polly?=	../../devel/polly

.include "../../lang/llvm/buildlink3.mk"
.endif	# POLLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-polly
