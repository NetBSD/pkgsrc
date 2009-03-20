# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:38 joerg Exp $

BUILDLINK_TREE+=	freeglut

.if !defined(FREEGLUT_BUILDLINK3_MK)
FREEGLUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freeglut+=	freeglut>=2.2.0
BUILDLINK_ABI_DEPENDS.freeglut+=	freeglut>=2.2.0nb3
BUILDLINK_PKGSRCDIR.freeglut?=	../../graphics/freeglut

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif # FREEGLUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-freeglut
