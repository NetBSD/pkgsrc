# $NetBSD: buildlink3.mk,v 1.2 2021/01/11 18:21:30 schmonz Exp $

BUILDLINK_TREE+=	skalibs

.if !defined(SKALIBS_BUILDLINK3_MK)
SKALIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.skalibs+=		skalibs>=2.10.0.0
BUILDLINK_PKGSRCDIR.skalibs?=		../../devel/skalibs

.endif # SKALIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-skalibs
