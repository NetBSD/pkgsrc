# $NetBSD: buildlink3.mk,v 1.34 2009/03/20 19:24:39 joerg Exp $

BUILDLINK_TREE+=	glu

.if !defined(GLU_BUILDLINK3_MK)
GLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glu+=	glu>=3.4.2
BUILDLINK_ABI_DEPENDS.glu+=	glu>=7.0.3
BUILDLINK_PKGSRCDIR.glu?=	../../graphics/glu

.include "../../graphics/MesaLib/buildlink3.mk"
.endif # GLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-glu
