# $NetBSD: buildlink3.mk,v 1.13 2026/03/25 22:56:25 wiz Exp $

BUILDLINK_TREE+=	polly

.if !defined(POLLY_BUILDLINK3_MK)
POLLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.polly+=	polly>=20.1.0
BUILDLINK_PKGSRCDIR.polly?=	../../devel/polly

.include "../../lang/llvm/buildlink3.mk"
.endif	# POLLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-polly
