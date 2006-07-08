# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 22:39:17 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
RENDERKIT_BUILDLINK3_MK:=	${RENDERKIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	RenderKit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NRenderKit}
BUILDLINK_PACKAGES+=	RenderKit
BUILDLINK_ORDER+=	RenderKit

.if !empty(RENDERKIT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.RenderKit+=	RenderKit>=0.3.1r2nb3
BUILDLINK_ABI_DEPENDS.RenderKit?=	RenderKit>=0.3.1r2nb10
BUILDLINK_PKGSRCDIR.RenderKit?=	../../graphics/RenderKit
.endif	# RENDERKIT_BUILDLINK3_MK

.include "../../graphics/GeometryKit/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
