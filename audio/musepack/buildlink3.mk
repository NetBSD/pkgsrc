# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:03:56 rillig Exp $

BUILDLINK_TREE+=	musepack

.if !defined(MUSEPACK_BUILDLINK3_MK)
MUSEPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.musepack+=	musepack>=0rc475
BUILDLINK_PKGSRCDIR.musepack?=		../../audio/musepack

.endif	# MUSEPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-musepack
