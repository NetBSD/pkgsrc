# $NetBSD: buildlink3.mk,v 1.7 2006/01/24 07:32:34 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GKRELLM_BUILDLINK3_MK:=	${GKRELLM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gkrellm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngkrellm}
BUILDLINK_PACKAGES+=	gkrellm

.if !empty(GKRELLM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gkrellm+=	gkrellm>=2.1.22
BUILDLINK_RECOMMENDED.gkrellm?=	gkrellm>=2.2.7
BUILDLINK_PKGSRCDIR.gkrellm?=	../../sysutils/gkrellm
.endif	# GKRELLM_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
