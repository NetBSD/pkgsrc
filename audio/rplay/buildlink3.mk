# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:08 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RPLAY_BUILDLINK3_MK:=	${RPLAY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	rplay
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrplay}
BUILDLINK_PACKAGES+=	rplay

.if !empty(RPLAY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.rplay+=	rplay>=3.3.2nb1
BUILDLINK_PKGSRCDIR.rplay?=	../../audio/rplay
.endif	# RPLAY_BUILDLINK3_MK

.include "../../audio/gsm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
