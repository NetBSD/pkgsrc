# $NetBSD: buildlink3.mk,v 1.1 2004/02/14 18:04:39 minskim Exp $
#
# This Makefile fragment is included by packages that use gtkspell.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKSPELL_BUILDLINK3_MK:=	${GTKSPELL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkspell
.endif

.if !empty(GTKSPELL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gtkspell
BUILDLINK_DEPENDS.gtkspell+=		gtkspell>=2.0.2nb6
BUILDLINK_PKGSRCDIR.gtkspell?=		../../textproc/gtkspell

.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # GTKSPELL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
