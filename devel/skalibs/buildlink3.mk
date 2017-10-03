# $NetBSD: buildlink3.mk,v 1.1 2017/10/03 00:31:39 schmonz Exp $

BUILDLINK_TREE+=	skalibs

.if !defined(SKALIBS_BUILDLINK3_MK)
SKALIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.skalibs+=		skalibs>=2.6.0.0
BUILDLINK_PKGSRCDIR.skalibs?=		../../devel/skalibs

.endif # SKALIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-skalibs
