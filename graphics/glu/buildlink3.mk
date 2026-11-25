# $NetBSD: buildlink3.mk,v 1.36 2026/11/25 14:42:12 wiz Exp $

BUILDLINK_TREE+=	glu

.if !defined(GLU_BUILDLINK3_MK)
GLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glu+=	glu>=3.4.2
BUILDLINK_ABI_DEPENDS.glu+=	glu>=7.11.2
BUILDLINK_PKGSRCDIR.glu?=	../../graphics/glu

.include "../../mk/mesa.buildlink3.mk"
.endif # GLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-glu
