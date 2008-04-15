# $NetBSD: buildlink3.mk,v 1.13 2008/04/15 17:41:13 drochner Exp $

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
BUILDLINK_ABI_DEPENDS.librsvg+=		librsvg>=2.18.2nb4
BUILDLINK_PKGSRCDIR.librsvg?=		../../graphics/librsvg
.endif	# LIBRSVG_BUILDLINK3_MK

.include "../../devel/libgsf/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
