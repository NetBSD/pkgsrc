# $NetBSD: buildlink3.mk,v 1.20 2023/10/24 22:08:59 wiz Exp $

BUILDLINK_TREE+=	ucommon

.if !defined(UCOMMON_BUILDLINK3_MK)
UCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ucommon+=	ucommon>=6.0.0
BUILDLINK_ABI_DEPENDS.ucommon+=	ucommon>=7.0.0nb11
BUILDLINK_PKGSRCDIR.ucommon?=	../../devel/ucommon

pkgbase := ucommon
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ucommon:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ucommon:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ucommon:Mstatic)
BUILDLINK_DEPMETHOD.ucommon?=	build
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # UCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ucommon
