# $NetBSD: buildlink3.mk,v 1.60 2023/10/24 22:11:07 wiz Exp $

BUILDLINK_TREE+=	gkrellm

.if !defined(GKRELLM_BUILDLINK3_MK)
GKRELLM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gkrellm+=	gkrellm>=2.1.22
BUILDLINK_ABI_DEPENDS.gkrellm+=	gkrellm>=2.2.10nb53
BUILDLINK_PKGSRCDIR.gkrellm?=	../../sysutils/gkrellm

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

pkgbase := gkrellm
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.gkrellm:Mopenssl}
.include "../../security/openssl/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gkrellm:Mgnutls}
.include "../../security/gnutls/buildlink3.mk"
.endif

.endif # GKRELLM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gkrellm
