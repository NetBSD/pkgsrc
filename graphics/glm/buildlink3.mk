# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/06 08:23:22 ryoon Exp $

BUILDLINK_TREE+=	glm

.if !defined(GLM_BUILDLINK3_MK)
GLM_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.glm?=	build

BUILDLINK_API_DEPENDS.glm+=	glm>=0.9.3.2
BUILDLINK_PKGSRCDIR.glm?=	../../graphics/glm
.endif	# GLM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glm
