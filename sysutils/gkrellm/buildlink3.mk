# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/24 22:11:28 cube Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GKRELLM_BUILDLINK3_MK:=	${GKRELLM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gkrellm
.endif

.if !empty(GKRELLM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gkrellm
BUILDLINK_DEPENDS.gkrellm+=		gkrellm>=2.1.22
BUILDLINK_PKGSRCDIR.gkrellm?=		../../sysutils/gkrellm
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.endif # GKRELLM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
