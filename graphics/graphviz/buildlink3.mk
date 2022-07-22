# $NetBSD: buildlink3.mk,v 1.29 2022/07/22 12:04:46 micha Exp $

BUILDLINK_TREE+=	graphviz

.if !defined(GRAPHVIZ_BUILDLINK3_MK)
GRAPHVIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=5.0.0
BUILDLINK_PKGSRCDIR.graphviz?=		../../graphics/graphviz

DEPENDS+=	urw-fonts-[0-9]*:../../fonts/urw-fonts

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # GRAPHVIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphviz
