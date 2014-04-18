# $NetBSD: buildlink3.mk,v 1.1 2014/04/18 12:43:42 wiz Exp $

BUILDLINK_TREE+=	musepack

.if !defined(MUSEPACK_BUILDLINK3_MK)
MUSEPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.musepack+=	musepack>=0rc475
BUILDLINK_PKGSRCDIR.musepack?=	../../audio/musepack

.endif	# MUSEPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-musepack
