# $NetBSD: buildlink3.mk,v 1.3 2009/08/31 12:38:22 adam Exp $

BUILDLINK_TREE+=	glew

.if !defined(GLEW_BUILDLINK3_MK)
GLEW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glew+=	glew>=1.3.4
BUILDLINK_ABI_DEPENDS.glew+=	glew>=1.3.4
BUILDLINK_PKGSRCDIR.glew?=	../../graphics/glew

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
.endif # GLEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-glew
