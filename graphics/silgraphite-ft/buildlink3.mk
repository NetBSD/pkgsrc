# $NetBSD: buildlink3.mk,v 1.5 2013/06/03 10:05:21 wiz Exp $

BUILDLINK_TREE+=	silgraphite-ft

.if !defined(SILGRAPHITE_FT_BUILDLINK3_MK)
SILGRAPHITE_FT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.silgraphite-ft+=	silgraphite-ft>=2.2.0
BUILDLINK_ABI_DEPENDS.silgraphite-ft+=	silgraphite-ft>=2.3.1nb2
BUILDLINK_PKGSRCDIR.silgraphite-ft?=	../../graphics/silgraphite-ft

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/silgraphite/buildlink3.mk"
.endif # SILGRAPHITE_FT_BUILDLINK3_MK

BUILDLINK_TREE+=	-silgraphite-ft
