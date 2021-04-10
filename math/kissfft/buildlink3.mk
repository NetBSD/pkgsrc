# $NetBSD: buildlink3.mk,v 1.1 2021/04/10 08:28:24 nia Exp $

BUILDLINK_TREE+=	kissfft

.if !defined(KISSFFT_BUILDLINK3_MK)
KISSFFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kissfft+=	kissfft>=131.1.0
BUILDLINK_PKGSRCDIR.kissfft?=	../../math/kissfft
.endif	# KISSFFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kissfft
