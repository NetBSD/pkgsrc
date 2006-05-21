# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/05/21 10:16:55 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TWOLAME_BUILDLINK3_MK:=	${TWOLAME_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	twolame
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntwolame}
BUILDLINK_PACKAGES+=	twolame

.if ${TWOLAME_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.twolame+=	twolame>=0.3.7
BUILDLINK_PKGSRCDIR.twolame?=	../../audio/twolame
.endif	# TWOLAME_BUILDLINK3_MK

.include "../../audio/libsndfile/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
