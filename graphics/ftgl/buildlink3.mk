# $NetBSD: buildlink3.mk,v 1.4 2026/11/25 14:42:11 wiz Exp $

BUILDLINK_TREE+=	ftgl

.if !defined(FTGL_BUILDLINK3_MK)
FTGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ftgl+=	ftgl>=2.1.3rc5
BUILDLINK_ABI_DEPENDS.ftgl?=	ftgl>=2.1.3rc5nb2
BUILDLINK_PKGSRCDIR.ftgl?=	../../graphics/ftgl

.include "../../mk/mesa.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif	# FTGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ftgl
