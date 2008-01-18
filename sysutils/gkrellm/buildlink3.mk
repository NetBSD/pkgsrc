# $NetBSD: buildlink3.mk,v 1.14 2008/01/18 05:09:43 tnn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GKRELLM_BUILDLINK3_MK:=	${GKRELLM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gkrellm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngkrellm}
BUILDLINK_PACKAGES+=	gkrellm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gkrellm

.if !empty(GKRELLM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gkrellm+=	gkrellm>=2.1.22
BUILDLINK_ABI_DEPENDS.gkrellm?=	gkrellm>=2.2.10nb1
BUILDLINK_PKGSRCDIR.gkrellm?=	../../sysutils/gkrellm
.endif	# GKRELLM_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
