# $NetBSD: buildlink3.mk,v 1.1 2004/02/22 16:51:07 minskim Exp $
#
# This Makefile fragment is included by packages that use rplay.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RPLAY_BUILDLINK3_MK:=	${RPLAY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	rplay
.endif

.if !empty(RPLAY_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			rplay
BUILDLINK_DEPENDS.rplay+=		rplay>=3.3.2nb1
BUILDLINK_PKGSRCDIR.rplay?=		../../audio/rplay

.include "../../audio/gsm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"

.endif # RPLAY_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
