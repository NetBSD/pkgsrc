# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 04:35:20 xtraeme Exp $
#
# This Makefile fragment is included by packages that use aspell.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ASPELL_BUILDLINK3_MK:=	${ASPELL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	aspell
.endif

.if !empty(ASPELL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			aspell
BUILDLINK_DEPENDS.aspell+=		aspell>=0.50.3nb2
BUILDLINK_PKGSRCDIR.aspell?=		../../textproc/aspell

.include "../../devel/ncurses/buildlink3.mk"

.endif # ASPELL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
