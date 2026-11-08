# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 15:15:55 ryoon Exp $

BUILDLINK_TREE+=	materialx

.if !defined(MATERIALX_BUILDLINK3_MK)
MATERIALX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.materialx+=	materialx>=1.39.5
BUILDLINK_PKGSRCDIR.materialx?=		../../graphics/materialx

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif	# MATERIALX_BUILDLINK3_MK

BUILDLINK_TREE+=	-materialx
