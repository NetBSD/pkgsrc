# $NetBSD: buildlink3.mk,v 1.10 2007/09/20 21:36:56 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBRSVG_BUILDLINK3_MK:=		${LIBRSVG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	librsvg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibrsvg}
BUILDLINK_PACKAGES+=	librsvg
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}librsvg

.if !empty(LIBRSVG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.librsvg+=		librsvg>=2.12.6nb1
BUILDLINK_ABI_DEPENDS.librsvg+=		librsvg>=2.16.1nb2
BUILDLINK_PKGSRCDIR.librsvg?=		../../graphics/librsvg
.endif	# LIBRSVG_BUILDLINK3_MK

.include "../../devel/libgsf/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
