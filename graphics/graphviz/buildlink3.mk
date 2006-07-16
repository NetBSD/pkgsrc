# $NetBSD: buildlink3.mk,v 1.12 2006/07/16 15:02:43 seb Exp $

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
# The configure script requires gd>=2.0.34, which was never released.
# Uncomment the following when graphics/gd is updated to 2.0.34
#.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
