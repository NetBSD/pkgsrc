# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:10:51 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GRAPHVIZ_BUILDLINK3_MK:=	${GRAPHVIZ_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	graphviz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngraphviz}
BUILDLINK_PACKAGES+=	graphviz
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}graphviz

.if !empty(GRAPHVIZ_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=1.12
BUILDLINK_ABI_DEPENDS.graphviz+=	graphviz>=2.6nb5
BUILDLINK_PKGSRCDIR.graphviz?=	../../graphics/graphviz
.endif	# GRAPHVIZ_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
