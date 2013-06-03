# $NetBSD: buildlink3.mk,v 1.22 2013/06/03 10:05:13 wiz Exp $

BUILDLINK_TREE+=	graphviz

.if !defined(GRAPHVIZ_BUILDLINK3_MK)
GRAPHVIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=2.26.3
BUILDLINK_ABI_DEPENDS.graphviz+=	graphviz>=2.26.3nb25
BUILDLINK_PKGSRCDIR.graphviz?=	../../graphics/graphviz

# doxygen PLIST varies with pangocairo of PKG_OPTIONS
pkgbase := graphviz
.include "../../mk/pkg-build-options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # GRAPHVIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphviz
