# $NetBSD: buildlink3.mk,v 1.46 2018/11/12 03:51:24 ryoon Exp $

BUILDLINK_TREE+=	gkrellm

.if !defined(GKRELLM_BUILDLINK3_MK)
GKRELLM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gkrellm+=	gkrellm>=2.1.22
BUILDLINK_ABI_DEPENDS.gkrellm+=	gkrellm>=2.2.10nb34
BUILDLINK_PKGSRCDIR.gkrellm?=	../../sysutils/gkrellm

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GKRELLM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gkrellm
