# $NetBSD: buildlink3.mk,v 1.2 2026/11/25 14:42:13 wiz Exp $

BUILDLINK_TREE+=	glw

.if !defined(GLW_BUILDLINK3_MK)
GLW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glw+=	glw>=8.0.0
BUILDLINK_PKGSRCDIR.glw?=	../../graphics/glw

.include "../../mk/mesa.buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif	# GLW_BUILDLINK3_MK

BUILDLINK_TREE+=	-glw
