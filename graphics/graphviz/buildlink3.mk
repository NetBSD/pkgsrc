# $NetBSD: buildlink3.mk,v 1.39 2024/07/05 10:34:12 micha Exp $

BUILDLINK_TREE+=	graphviz

.if !defined(GRAPHVIZ_BUILDLINK3_MK)
GRAPHVIZ_BUILDLINK3_MK:=

USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++11 unique_ptr

BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=2.26.3
BUILDLINK_ABI_DEPENDS.graphviz+=	graphviz>=12.0.0
BUILDLINK_PKGSRCDIR.graphviz?=		../../graphics/graphviz

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.endif # GRAPHVIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-graphviz
