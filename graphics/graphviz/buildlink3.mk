# $NetBSD: buildlink3.mk,v 1.14 2008/02/06 18:56:52 adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GRAPHVIZ_BUILDLINK3_MK:=	${GRAPHVIZ_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	graphviz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngraphviz}
BUILDLINK_PACKAGES+=	graphviz
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}graphviz

.if ${GRAPHVIZ_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=1.12
BUILDLINK_ABI_DEPENDS.graphviz+=	graphviz>=2.6nb5
BUILDLINK_PKGSRCDIR.graphviz?=	../../graphics/graphviz
.endif	# GRAPHVIZ_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
