# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:34:43 xtraeme Exp $
#
# This Makefile fragment is included by packages that use lame.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LAME_BUILDLINK3_MK:=	${LAME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	lame
.endif

.if !empty(LAME_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			lame
BUILDLINK_DEPENDS.lame+=		lame>=3.93.1nb2
BUILDLINK_PKGSRCDIR.lame?=		../../audio/lame

.include "../../devel/ncurses/buildlink3.mk"

.endif # LAME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
