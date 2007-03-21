# $NetBSD: buildlink3.mk,v 1.22 2007/03/21 12:05:47 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBRSVG2_BUILDLINK3_MK:=	${LIBRSVG2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	librsvg2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibrsvg2}
BUILDLINK_PACKAGES+=	librsvg2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}librsvg2

.if !empty(LIBRSVG2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.librsvg2+=	librsvg2>=2.12.6nb1
BUILDLINK_ABI_DEPENDS.librsvg2+=	librsvg2>=2.16.1nb1
BUILDLINK_PKGSRCDIR.librsvg2?=	../../graphics/librsvg2
.endif	# LIBRSVG2_BUILDLINK3_MK

.include "../../devel/libgsf/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
