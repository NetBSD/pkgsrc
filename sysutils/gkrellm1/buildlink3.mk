# $NetBSD: buildlink3.mk,v 1.1 2004/03/12 04:56:49 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GKRELLM_BUILDLINK3_MK:=	${GKRELLM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gkrellm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngkrellm}
BUILDLINK_PACKAGES+=	gkrellm

.if !empty(GKRELLM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gkrellm+=	gkrellm>=1.2.13nb3
BUILDLINK_PKGSRCDIR.gkrellm?=	../../sysutils/gkrellm1

.include "../../graphics/imlib/buildlink3.mk"

.endif	# GKRELLM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
