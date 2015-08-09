# $NetBSD: buildlink3.mk,v 1.3 2015/08/09 11:17:00 wiz Exp $

BUILDLINK_TREE+=	glm

.if !defined(GLM_BUILDLINK3_MK)
GLM_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.glm?=	build

BUILDLINK_API_DEPENDS.glm+=	glm>=0.9.7
BUILDLINK_PKGSRCDIR.glm?=	../../graphics/glm
.endif	# GLM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glm
