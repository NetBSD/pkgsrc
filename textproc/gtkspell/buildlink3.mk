# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:15 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKSPELL_BUILDLINK3_MK:=	${GTKSPELL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkspell
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkspell}
BUILDLINK_PACKAGES+=	gtkspell

.if !empty(GTKSPELL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkspell+=	gtkspell>=2.0.2nb6
BUILDLINK_PKGSRCDIR.gtkspell?=	../../textproc/gtkspell
.endif	# GTKSPELL_BUILDLINK3_MK

.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
