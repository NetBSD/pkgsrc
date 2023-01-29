# $NetBSD: buildlink3.mk,v 1.2 2023/01/29 21:14:39 ryoon Exp $

BUILDLINK_TREE+=	ftgl

.if !defined(FTGL_BUILDLINK3_MK)
FTGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ftgl+=	ftgl>=2.1.3rc5
BUILDLINK_ABI_DEPENDS.ftgl?=	ftgl>=2.1.3rc5nb1
BUILDLINK_PKGSRCDIR.ftgl?=	../../graphics/ftgl

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif	# FTGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ftgl
