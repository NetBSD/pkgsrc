# $NetBSD: buildlink3.mk,v 1.35 2013/05/16 05:25:02 richard Exp $

BUILDLINK_TREE+=	glu

.if !defined(GLU_BUILDLINK3_MK)
GLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glu+=	glu>=3.4.2
BUILDLINK_ABI_DEPENDS.glu+=	glu>=7.11.2
BUILDLINK_PKGSRCDIR.glu?=	../../graphics/glu

.include "../../graphics/MesaLib/buildlink3.mk"
.endif # GLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-glu
