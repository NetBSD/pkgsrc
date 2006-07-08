# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:10 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKSPELL_BUILDLINK3_MK:=	${GTKSPELL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkspell
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkspell}
BUILDLINK_PACKAGES+=	gtkspell
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtkspell

.if !empty(GTKSPELL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gtkspell+=	gtkspell>=2.0.2nb6
BUILDLINK_ABI_DEPENDS.gtkspell+=	gtkspell>=2.0.11nb3
BUILDLINK_PKGSRCDIR.gtkspell?=	../../textproc/gtkspell
.endif	# GTKSPELL_BUILDLINK3_MK

.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
