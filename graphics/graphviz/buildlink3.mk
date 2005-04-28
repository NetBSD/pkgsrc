# $NetBSD: buildlink3.mk,v 1.3 2005/04/28 14:58:06 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GRAPHVIZ_BUILDLINK3_MK:=	${GRAPHVIZ_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	graphviz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngraphviz}
BUILDLINK_PACKAGES+=	graphviz

.if !empty(GRAPHVIZ_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.graphviz+=	graphviz>=1.12
BUILDLINK_RECOMMENDED.graphviz+=	graphviz>=1.12nb1
BUILDLINK_PKGSRCDIR.graphviz?=	../../graphics/graphviz
.endif	# GRAPHVIZ_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
