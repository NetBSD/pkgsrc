# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:36 joerg Exp $

BUILDLINK_TREE+=	RenderKit

.if !defined(RENDERKIT_BUILDLINK3_MK)
RENDERKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.RenderKit+=	RenderKit>=0.3.1r2nb3
BUILDLINK_ABI_DEPENDS.RenderKit?=	RenderKit>=0.3.1r2nb12
BUILDLINK_PKGSRCDIR.RenderKit?=	../../graphics/RenderKit

.include "../../graphics/GeometryKit/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif # RENDERKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-RenderKit
