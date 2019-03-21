# $NetBSD: buildlink3.mk,v 1.1 2019/03/21 12:18:56 jaapb Exp $

BUILDLINK_TREE+=	menhir

.if !defined(MENHIR_BUILDLINK3_MK)
MENHIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.menhir+=	menhir>=20180530
BUILDLINK_PKGSRCDIR.menhir?=	../../devel/menhir

.endif	# MENHIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-menhir
