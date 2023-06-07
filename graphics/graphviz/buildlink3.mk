# $NetBSD: buildlink3.mk,v 1.35 2023/06/07 10:09:48 micha Exp $

BUILDLINK_TREE+=	graphviz

.if !defined(GRAPHVIZ_BUILDLINK3_MK)
GRAPHVIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=2.26.3
BUILDLINK_ABI_DEPENDS.graphviz+=	graphviz>=8.0.5
BUILDLINK_PKGSRCDIR.graphviz?=		../../graphics/graphviz

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # GRAPHVIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphviz
