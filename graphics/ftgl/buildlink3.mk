# $NetBSD: buildlink3.mk,v 1.1 2019/09/08 20:41:10 nia Exp $

BUILDLINK_TREE+=	ftgl

.if !defined(FTGL_BUILDLINK3_MK)
FTGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ftgl+=	ftgl>=2.1.3rc5
BUILDLINK_PKGSRCDIR.ftgl?=	../../graphics/ftgl

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif	# FTGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ftgl
