# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/02/26 20:41:04 reinoud Exp $

BUILDLINK_TREE+=	opencsg

.if !defined(OPENCSG_BUILDLINK3_MK)
OPENCSG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencsg+=	opencsg>=1.3.2
BUILDLINK_PKGSRCDIR.opencsg?=	../../graphics/opencsg

.include "../../graphics/glew/buildlink3.mk"
.endif	# OPENCSG_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencsg
