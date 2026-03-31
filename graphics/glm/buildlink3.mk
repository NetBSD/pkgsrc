# $NetBSD: buildlink3.mk,v 1.4 2026/03/31 10:46:00 adam Exp $

BUILDLINK_TREE+=	glm

.if !defined(GLM_BUILDLINK3_MK)
GLM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glm+=	glm>=0.9.7
BUILDLINK_PKGSRCDIR.glm?=	../../graphics/glm
.endif	# GLM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glm
