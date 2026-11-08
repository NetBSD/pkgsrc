# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 16:08:42 ryoon Exp $

BUILDLINK_TREE+=	clipper2

.if !defined(CLIPPER2_BUILDLINK3_MK)
CLIPPER2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clipper2+=	clipper2>=2.0.1
BUILDLINK_PKGSRCDIR.clipper2?=		../../cad/clipper2

.endif	# CLIPPER2_BUILDLINK3_MK

BUILDLINK_TREE+=	-clipper2
