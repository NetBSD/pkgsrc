# $NetBSD: buildlink3.mk,v 1.1 2025/02/10 10:49:53 adam Exp $

BUILDLINK_TREE+=	ade

.if !defined(ADE_BUILDLINK3_MK)
ADE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.ade?=	build

BUILDLINK_API_DEPENDS.ade+=	ade>=0.1.2e
BUILDLINK_PKGSRCDIR.ade?=	../../devel/ade
.endif	# ADE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ade
