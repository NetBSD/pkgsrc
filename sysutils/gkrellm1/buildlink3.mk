# $NetBSD: buildlink3.mk,v 1.4 2006/02/05 23:10:50 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GKRELLM_BUILDLINK3_MK:=	${GKRELLM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gkrellm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngkrellm}
BUILDLINK_PACKAGES+=	gkrellm

.if !empty(GKRELLM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gkrellm+=	gkrellm<2.0
BUILDLINK_RECOMMENDED.gkrellm?=	gkrellm>=1.2.13nb5
BUILDLINK_PKGSRCDIR.gkrellm?=	../../sysutils/gkrellm1
.endif	# GKRELLM_BUILDLINK3_MK

.include "../../graphics/imlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
