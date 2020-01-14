# $NetBSD: buildlink3.mk,v 1.2 2020/01/14 22:04:26 jaapb Exp $

BUILDLINK_TREE+=	menhir

.if !defined(MENHIR_BUILDLINK3_MK)
MENHIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.menhir+=	menhir>=20190626
BUILDLINK_ABI_DEPENDS.menhir+=	menhir>=20190924
BUILDLINK_PKGSRCDIR.menhir?=	../../devel/menhir

.endif	# MENHIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-menhir
