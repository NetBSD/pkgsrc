# $NetBSD: buildlink3.mk,v 1.4 2004/10/03 00:13:09 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RPLAY_BUILDLINK3_MK:=	${RPLAY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	rplay
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrplay}
BUILDLINK_PACKAGES+=	rplay

.if !empty(RPLAY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.rplay+=	rplay>=3.3.2nb1
BUILDLINK_RECOMMENDED.rplay+=	rplay>=3.3.2nb2
BUILDLINK_PKGSRCDIR.rplay?=	../../audio/rplay
.endif	# RPLAY_BUILDLINK3_MK

.include "../../audio/gsm/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
