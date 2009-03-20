# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:35 joerg Exp $

BUILDLINK_TREE+=	GeometryKit

.if !defined(GEOMETRYKIT_BUILDLINK3_MK)
GEOMETRYKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.GeometryKit+=	GeometryKit>=0.3.1r2nb3
BUILDLINK_ABI_DEPENDS.GeometryKit?=	GeometryKit>=0.3.1r2nb12
BUILDLINK_PKGSRCDIR.GeometryKit?=	../../graphics/GeometryKit

.include "../../x11/gnustep-back/buildlink3.mk"
.endif # GEOMETRYKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-GeometryKit
