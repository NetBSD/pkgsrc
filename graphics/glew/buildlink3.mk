# $NetBSD: buildlink3.mk,v 1.7 2026/11/25 14:42:12 wiz Exp $

BUILDLINK_TREE+=	glew

.if !defined(GLEW_BUILDLINK3_MK)
GLEW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glew+=	glew>=1.3.4
BUILDLINK_ABI_DEPENDS.glew+=	glew>=2.1.0
BUILDLINK_PKGSRCDIR.glew?=	../../graphics/glew

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../mk/mesa.buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif
.endif # GLEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-glew
