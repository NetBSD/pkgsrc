# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:09 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
STREAMTUNER_BUILDLINK3_MK:=	${STREAMTUNER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	streamtuner
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nstreamtuner}
BUILDLINK_PACKAGES+=	streamtuner

.if !empty(STREAMTUNER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.streamtuner+=		streamtuner>=0.12.1
BUILDLINK_RECOMMENDED.streamtuner+=	streamtuner>=0.12.1nb1
BUILDLINK_PKGSRCDIR.streamtuner?=	../../audio/streamtuner
.endif	# STREAMTUNER_BUILDLINK3_MK

.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
