# $NetBSD: buildlink3.mk,v 1.5 2008/11/16 11:22:55 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JACK_BUILDLINK3_MK:=	${JACK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	jack
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Njack}
BUILDLINK_PACKAGES+=	jack
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}jack

.if ${JACK_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.jack+=	jack>=0.110.0
BUILDLINK_PKGSRCDIR.jack?=	../../audio/jack
.endif	# JACK_BUILDLINK3_MK

.include "../../audio/libsamplerate/buildlink3.mk"
# for DLOPEN_REQUIRE_PTHREADS
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
