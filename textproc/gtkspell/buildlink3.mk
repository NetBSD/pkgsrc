# $NetBSD: buildlink3.mk,v 1.12 2008/05/30 12:28:42 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKSPELL_BUILDLINK3_MK:=	${GTKSPELL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkspell
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkspell}
BUILDLINK_PACKAGES+=	gtkspell
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtkspell

.if !empty(GTKSPELL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtkspell+=	gtkspell>=2.0.13
BUILDLINK_PKGSRCDIR.gtkspell?=	../../textproc/gtkspell
.endif	# GTKSPELL_BUILDLINK3_MK

.include "../../textproc/enchant/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
