# $NetBSD: buildlink3.mk,v 1.1 2016/10/18 02:47:16 kamil Exp $

BUILDLINK_TREE+=	ptex

.if !defined(PTEX_BUILDLINK3_MK)
PTEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ptex+=	ptex>=2.1.28
BUILDLINK_PKGSRCDIR.ptex?=	../../graphics/ptex
.endif	# PTEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ptex
