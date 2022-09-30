# $NetBSD: buildlink3.mk,v 1.32 2022/09/30 16:08:52 micha Exp $

BUILDLINK_TREE+=	graphviz

.if !defined(GRAPHVIZ_BUILDLINK3_MK)
GRAPHVIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=2.26.3
BUILDLINK_ABI_DEPENDS.graphviz+=	graphviz>=6.0.1
BUILDLINK_PKGSRCDIR.graphviz?=		../../graphics/graphviz

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # GRAPHVIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphviz
