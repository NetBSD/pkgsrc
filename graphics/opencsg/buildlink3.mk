# $NetBSD: buildlink3.mk,v 1.2 2012/08/31 16:29:49 adam Exp $

BUILDLINK_TREE+=	opencsg

.if !defined(OPENCSG_BUILDLINK3_MK)
OPENCSG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencsg+=	opencsg>=1.3.2
BUILDLINK_PKGSRCDIR.opencsg?=	../../graphics/opencsg

.endif	# OPENCSG_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencsg
